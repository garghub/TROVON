static bool F_1 ( const struct V_1 * V_2 , const struct V_1 * V_3 )
{
return V_2 -> V_4 < V_3 -> V_4 || V_2 -> V_5 < V_3 -> V_5 ;
}
static bool F_2 ( const struct V_1 * V_2 , const struct V_1 * V_3 )
{
return V_2 -> V_6 > V_3 -> V_6 || V_2 -> V_7 > V_3 -> V_7 ||
V_2 -> V_6 + V_2 -> V_4 < V_3 -> V_6 + V_3 -> V_4 ||
V_2 -> V_7 + V_2 -> V_5 < V_3 -> V_7 + V_3 -> V_5 ;
}
int F_3 ( struct V_8 * V_9 , struct V_1 * V_10 )
{
struct V_11 V_12 ;
struct V_13 V_14 ;
int V_15 ;
V_12 . type = V_16 ;
V_15 = F_4 ( V_9 , V_17 , V_18 , & V_12 ) ;
if ( ! V_15 ) {
* V_10 = V_12 . V_19 ;
return V_15 ;
}
V_14 . type = V_16 ;
V_15 = F_4 ( V_9 , V_17 , V_20 , & V_14 ) ;
if ( ! V_15 )
* V_10 = V_14 . V_21 ;
return V_15 ;
}
static void F_5 ( struct V_1 * V_10 , struct V_1 * V_22 )
{
if ( V_10 -> V_4 < V_22 -> V_4 )
V_22 -> V_4 = V_10 -> V_4 ;
if ( V_10 -> V_5 < V_22 -> V_5 )
V_22 -> V_5 = V_10 -> V_5 ;
if ( V_10 -> V_6 > V_22 -> V_6 )
V_22 -> V_6 = V_10 -> V_6 ;
else if ( V_10 -> V_6 + V_10 -> V_4 >
V_22 -> V_6 + V_22 -> V_4 )
V_22 -> V_6 = V_10 -> V_6 + V_10 -> V_4 -
V_22 -> V_4 ;
if ( V_10 -> V_7 > V_22 -> V_7 )
V_22 -> V_7 = V_10 -> V_7 ;
else if ( V_10 -> V_7 + V_10 -> V_5 >
V_22 -> V_7 + V_22 -> V_5 )
V_22 -> V_7 = V_10 -> V_7 + V_10 -> V_5 -
V_22 -> V_5 ;
}
int F_6 ( struct V_8 * V_9 ,
struct V_11 * V_12 , struct V_11 * V_23 ,
struct V_1 * V_24 , struct V_1 * V_22 )
{
struct V_1 * V_10 = & V_12 -> V_19 , * V_25 = & V_23 -> V_19 ;
struct V_26 * V_27 = V_9 -> V_28 -> V_27 ;
struct V_13 V_14 ;
int V_15 ;
unsigned int V_4 , V_5 ;
F_4 ( V_9 , V_17 , V_29 , V_12 ) ;
V_15 = F_3 ( V_9 , V_25 ) ;
if ( V_15 < 0 )
return V_15 ;
if ( ! memcmp ( V_10 , V_25 , sizeof( * V_10 ) ) ) {
F_7 ( V_27 , L_1 ,
V_10 -> V_4 , V_10 -> V_5 , V_10 -> V_6 , V_10 -> V_7 ) ;
* V_24 = * V_25 ;
return 0 ;
}
F_8 ( V_27 , L_2 ,
V_25 -> V_4 , V_25 -> V_5 ,
V_25 -> V_6 , V_25 -> V_7 ,
V_10 -> V_4 , V_10 -> V_5 , V_10 -> V_6 , V_10 -> V_7 ) ;
V_15 = F_4 ( V_9 , V_17 , V_20 , & V_14 ) ;
if ( V_15 < 0 )
return V_15 ;
F_9 ( & V_10 -> V_6 , & V_10 -> V_4 , V_14 . V_30 . V_6 , 2 ,
V_14 . V_30 . V_4 ) ;
F_9 ( & V_10 -> V_7 , & V_10 -> V_5 , V_14 . V_30 . V_7 , 4 ,
V_14 . V_30 . V_5 ) ;
V_4 = F_10 (unsigned int, cam_rect->width, 2 ) ;
V_5 = F_10 (unsigned int, cam_rect->height, 2 ) ;
while ( ! V_15 && ( F_1 ( V_25 , V_10 ) ||
F_2 ( V_25 , V_10 ) ) &&
( V_14 . V_30 . V_4 > V_4 || V_14 . V_30 . V_5 > V_5 ) ) {
V_4 *= 2 ;
V_5 *= 2 ;
V_25 -> V_4 = V_4 ;
V_25 -> V_5 = V_5 ;
if ( V_25 -> V_6 > V_10 -> V_6 )
V_25 -> V_6 = V_14 . V_30 . V_6 ;
if ( V_25 -> V_6 + V_25 -> V_4 < V_10 -> V_6 + V_10 -> V_4 )
V_25 -> V_4 = V_10 -> V_6 + V_10 -> V_4 -
V_25 -> V_6 ;
if ( V_25 -> V_7 > V_10 -> V_7 )
V_25 -> V_7 = V_14 . V_30 . V_7 ;
if ( V_25 -> V_7 + V_25 -> V_5 < V_10 -> V_7 + V_10 -> V_5 )
V_25 -> V_5 = V_10 -> V_7 + V_10 -> V_5 -
V_25 -> V_7 ;
F_4 ( V_9 , V_17 , V_29 , V_23 ) ;
V_15 = F_3 ( V_9 , V_25 ) ;
F_8 ( V_27 , L_3 , V_15 ,
V_25 -> V_4 , V_25 -> V_5 ,
V_25 -> V_6 , V_25 -> V_7 ) ;
}
if ( F_1 ( V_25 , V_10 ) || F_2 ( V_25 , V_10 ) ) {
* V_25 = V_14 . V_30 ;
F_4 ( V_9 , V_17 , V_29 , V_23 ) ;
V_15 = F_3 ( V_9 , V_25 ) ;
F_8 ( V_27 , L_4 , V_15 ,
V_25 -> V_4 , V_25 -> V_5 ,
V_25 -> V_6 , V_25 -> V_7 ) ;
}
if ( ! V_15 ) {
* V_24 = * V_25 ;
F_5 ( V_24 , V_22 ) ;
}
return V_15 ;
}
static int F_11 ( struct V_31 * V_32 ,
struct V_1 * V_10 , struct V_1 * V_22 ,
unsigned int V_33 , unsigned int V_34 ,
struct V_35 * V_36 , bool V_37 )
{
struct V_8 * V_9 = F_12 ( V_32 ) ;
struct V_26 * V_27 = V_32 -> V_38 ;
struct V_39 * V_40 = & V_36 -> V_36 ;
unsigned int V_4 = V_40 -> V_4 , V_5 = V_40 -> V_5 , V_41 , V_42 ;
struct V_13 V_14 ;
bool V_43 ;
int V_15 ;
V_15 = F_13 ( V_9 -> V_28 ,
F_14 ( V_32 ) , V_44 ,
V_45 , NULL , V_36 ) ;
if ( V_15 < 0 )
return V_15 ;
F_8 ( V_27 , L_5 , V_40 -> V_4 , V_40 -> V_5 ) ;
if ( V_4 == V_40 -> V_4 && V_5 == V_40 -> V_5 ) {
V_43 = true ;
goto V_46;
}
V_43 = false ;
if ( ! V_37 )
goto V_46;
V_14 . type = V_16 ;
V_15 = F_4 ( V_9 , V_17 , V_20 , & V_14 ) ;
if ( V_15 < 0 )
return V_15 ;
if ( V_33 > V_14 . V_30 . V_4 )
V_33 = V_14 . V_30 . V_4 ;
if ( V_34 > V_14 . V_30 . V_5 )
V_34 = V_14 . V_30 . V_5 ;
V_41 = V_40 -> V_4 ;
V_42 = V_40 -> V_5 ;
while ( ( V_4 > V_41 || V_5 > V_42 ) &&
V_41 < V_33 && V_42 < V_34 ) {
V_41 = F_15 ( 2 * V_41 , V_33 ) ;
V_42 = F_15 ( 2 * V_42 , V_34 ) ;
V_40 -> V_4 = V_41 ;
V_40 -> V_5 = V_42 ;
V_15 = F_13 ( V_9 -> V_28 ,
F_14 ( V_32 ) , V_44 ,
V_45 , NULL , V_36 ) ;
F_8 ( V_27 , L_6 ,
V_40 -> V_4 , V_40 -> V_5 ) ;
if ( V_15 < 0 ) {
F_16 ( V_27 , L_7 , V_15 ) ;
return V_15 ;
}
}
V_46:
V_15 = F_3 ( V_9 , V_10 ) ;
if ( V_15 < 0 )
return V_15 ;
if ( V_43 )
* V_22 = * V_10 ;
else
F_5 ( V_10 , V_22 ) ;
return 0 ;
}
int F_17 ( struct V_31 * V_32 ,
struct V_1 * V_10 , struct V_1 * V_22 ,
struct V_39 * V_40 ,
unsigned int * V_4 , unsigned int * V_5 ,
bool V_37 , unsigned int V_47 )
{
struct V_26 * V_27 = V_32 -> V_38 ;
struct V_35 V_48 = {
. V_49 = V_50 ,
. V_36 = * V_40 ,
} ;
struct V_39 * V_51 = & V_48 . V_36 ;
unsigned int V_52 , V_53 ;
int V_15 ;
V_15 = F_11 ( V_32 , V_10 , V_22 , * V_4 , * V_5 ,
& V_48 , V_37 ) ;
if ( V_15 < 0 )
return V_15 ;
F_8 ( V_27 , L_8 ,
V_51 -> V_4 , V_51 -> V_5 ) ;
V_52 = F_18 ( V_10 -> V_4 , V_47 , V_51 -> V_4 ) ;
V_53 = F_18 ( V_10 -> V_5 , V_47 , V_51 -> V_5 ) ;
V_40 -> V_4 = V_51 -> V_4 ;
V_40 -> V_5 = V_51 -> V_5 ;
V_40 -> V_54 = V_51 -> V_54 ;
* V_4 = F_19 ( V_22 -> V_4 , V_47 , V_52 ) ;
* V_5 = F_19 ( V_22 -> V_5 , V_47 , V_53 ) ;
F_8 ( V_27 , L_9 , * V_4 , * V_5 ) ;
return 0 ;
}
void F_20 ( struct V_31 * V_32 ,
struct V_1 * V_10 , struct V_1 * V_22 ,
const struct V_55 * V_56 , struct V_39 * V_40 ,
unsigned int V_47 )
{
struct V_26 * V_27 = V_32 -> V_38 ;
unsigned int V_53 , V_52 ;
if ( V_22 -> V_4 == V_10 -> V_4 &&
V_22 -> V_5 == V_10 -> V_5 ) {
V_40 -> V_4 = V_56 -> V_4 ;
V_40 -> V_5 = V_56 -> V_5 ;
return;
}
F_8 ( V_27 , L_10 ,
V_22 -> V_4 , V_22 -> V_5 ,
V_22 -> V_6 , V_22 -> V_7 ) ;
V_52 = F_18 ( V_22 -> V_4 , V_47 , V_56 -> V_4 ) ;
V_53 = F_18 ( V_22 -> V_5 , V_47 , V_56 -> V_5 ) ;
F_8 ( V_27 , L_11 , V_52 , V_53 ) ;
V_40 -> V_4 = F_19 ( V_10 -> V_4 , V_47 , V_52 ) ;
V_40 -> V_5 = F_19 ( V_10 -> V_5 , V_47 , V_53 ) ;
}
