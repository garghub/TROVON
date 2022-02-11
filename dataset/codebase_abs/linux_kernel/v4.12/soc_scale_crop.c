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
struct V_11 V_12 = {
. V_13 = V_14 ,
. V_15 = V_16 ,
} ;
int V_17 ;
V_17 = F_4 ( V_9 , V_18 , V_19 , NULL , & V_12 ) ;
if ( ! V_17 ) {
* V_10 = V_12 . V_20 ;
return V_17 ;
}
V_12 . V_15 = V_21 ;
V_17 = F_4 ( V_9 , V_18 , V_19 , NULL , & V_12 ) ;
if ( ! V_17 )
* V_10 = V_12 . V_20 ;
return V_17 ;
}
static void F_5 ( struct V_1 * V_10 ,
struct V_1 * V_22 )
{
if ( V_10 -> V_4 < V_22 -> V_4 )
V_22 -> V_4 = V_10 -> V_4 ;
if ( V_10 -> V_5 < V_22 -> V_5 )
V_22 -> V_5 = V_10 -> V_5 ;
if ( V_10 -> V_6 > V_22 -> V_6 )
V_22 -> V_6 = V_10 -> V_6 ;
else if ( V_10 -> V_6 + V_10 -> V_4 <
V_22 -> V_6 + V_22 -> V_4 )
V_22 -> V_6 = V_10 -> V_6 + V_10 -> V_4 -
V_22 -> V_4 ;
if ( V_10 -> V_7 > V_22 -> V_7 )
V_22 -> V_7 = V_10 -> V_7 ;
else if ( V_10 -> V_7 + V_10 -> V_5 <
V_22 -> V_7 + V_22 -> V_5 )
V_22 -> V_7 = V_10 -> V_7 + V_10 -> V_5 -
V_22 -> V_5 ;
}
int F_6 ( struct V_8 * V_9 ,
struct V_23 * V_24 , struct V_23 * V_25 ,
struct V_1 * V_26 , struct V_1 * V_22 )
{
struct V_11 V_12 = {
. V_13 = V_14 ,
. V_15 = V_24 -> V_15 ,
. V_27 = V_24 -> V_27 ,
. V_20 = V_24 -> V_20 ,
} ;
struct V_11 V_28 = {
. V_13 = V_14 ,
. V_15 = V_29 ,
} ;
struct V_1 * V_10 = & V_24 -> V_20 , * V_30 = & V_25 -> V_20 ;
struct V_31 * V_32 = V_9 -> V_33 -> V_32 ;
int V_17 ;
unsigned int V_4 , V_5 ;
F_4 ( V_9 , V_18 , V_34 , NULL , & V_12 ) ;
V_24 -> V_20 = V_12 . V_20 ;
V_17 = F_3 ( V_9 , V_30 ) ;
if ( V_17 < 0 )
return V_17 ;
if ( ! memcmp ( V_10 , V_30 , sizeof( * V_10 ) ) ) {
F_7 ( V_32 , L_1 ,
V_10 -> V_4 , V_10 -> V_5 , V_10 -> V_6 , V_10 -> V_7 ) ;
* V_26 = * V_30 ;
return 0 ;
}
F_8 ( V_32 , L_2 ,
V_30 -> V_4 , V_30 -> V_5 ,
V_30 -> V_6 , V_30 -> V_7 ,
V_10 -> V_4 , V_10 -> V_5 , V_10 -> V_6 , V_10 -> V_7 ) ;
V_17 = F_4 ( V_9 , V_18 , V_19 , NULL , & V_28 ) ;
if ( V_17 < 0 )
return V_17 ;
F_9 ( & V_10 -> V_6 , & V_10 -> V_4 , V_12 . V_20 . V_6 , 2 ,
V_28 . V_20 . V_4 ) ;
F_9 ( & V_10 -> V_7 , & V_10 -> V_5 , V_12 . V_20 . V_7 , 4 ,
V_28 . V_20 . V_5 ) ;
V_4 = F_10 (unsigned int, cam_rect->width, 2 ) ;
V_5 = F_10 (unsigned int, cam_rect->height, 2 ) ;
while ( ! V_17 && ( F_1 ( V_30 , V_10 ) ||
F_2 ( V_30 , V_10 ) ) &&
( V_28 . V_20 . V_4 > V_4 || V_28 . V_20 . V_5 > V_5 ) ) {
V_4 *= 2 ;
V_5 *= 2 ;
V_30 -> V_4 = V_4 ;
V_30 -> V_5 = V_5 ;
if ( V_30 -> V_6 > V_10 -> V_6 )
V_30 -> V_6 = V_28 . V_20 . V_6 ;
if ( V_30 -> V_6 + V_30 -> V_4 < V_10 -> V_6 + V_10 -> V_4 )
V_30 -> V_4 = V_10 -> V_6 + V_10 -> V_4 -
V_30 -> V_6 ;
if ( V_30 -> V_7 > V_10 -> V_7 )
V_30 -> V_7 = V_28 . V_20 . V_7 ;
if ( V_30 -> V_7 + V_30 -> V_5 < V_10 -> V_7 + V_10 -> V_5 )
V_30 -> V_5 = V_10 -> V_7 + V_10 -> V_5 -
V_30 -> V_7 ;
V_12 . V_20 = * V_30 ;
F_4 ( V_9 , V_18 , V_34 , NULL , & V_12 ) ;
* V_30 = V_12 . V_20 ;
V_17 = F_3 ( V_9 , V_30 ) ;
F_8 ( V_32 , L_3 , V_17 ,
V_30 -> V_4 , V_30 -> V_5 ,
V_30 -> V_6 , V_30 -> V_7 ) ;
}
if ( F_1 ( V_30 , V_10 ) || F_2 ( V_30 , V_10 ) ) {
V_12 . V_20 = V_28 . V_20 ;
F_4 ( V_9 , V_18 , V_34 , NULL , & V_12 ) ;
* V_30 = V_12 . V_20 ;
V_17 = F_3 ( V_9 , V_30 ) ;
F_8 ( V_32 , L_4 , V_17 ,
V_30 -> V_4 , V_30 -> V_5 ,
V_30 -> V_6 , V_30 -> V_7 ) ;
}
if ( ! V_17 ) {
* V_26 = * V_30 ;
F_5 ( V_26 , V_22 ) ;
}
return V_17 ;
}
static int F_11 ( struct V_35 * V_36 ,
struct V_1 * V_10 , struct V_1 * V_22 ,
unsigned int V_37 , unsigned int V_38 ,
struct V_39 * V_40 , bool V_41 )
{
struct V_8 * V_9 = F_12 ( V_36 ) ;
struct V_31 * V_32 = V_36 -> V_42 ;
struct V_43 * V_44 = & V_40 -> V_40 ;
unsigned int V_4 = V_44 -> V_4 , V_5 = V_44 -> V_5 , V_45 , V_46 ;
struct V_11 V_12 = {
. V_13 = V_14 ,
. V_15 = V_29 ,
} ;
bool V_47 ;
int V_17 ;
V_17 = F_13 ( V_9 -> V_33 ,
F_14 ( V_36 ) , V_18 ,
V_48 , NULL , V_40 ) ;
if ( V_17 < 0 )
return V_17 ;
F_8 ( V_32 , L_5 , V_44 -> V_4 , V_44 -> V_5 ) ;
if ( V_4 == V_44 -> V_4 && V_5 == V_44 -> V_5 ) {
V_47 = true ;
goto V_49;
}
V_47 = false ;
if ( ! V_41 )
goto V_49;
V_17 = F_4 ( V_9 , V_18 , V_19 , NULL , & V_12 ) ;
if ( V_17 < 0 )
return V_17 ;
if ( V_37 > V_12 . V_20 . V_4 )
V_37 = V_12 . V_20 . V_4 ;
if ( V_38 > V_12 . V_20 . V_5 )
V_38 = V_12 . V_20 . V_5 ;
V_45 = V_44 -> V_4 ;
V_46 = V_44 -> V_5 ;
while ( ( V_4 > V_45 || V_5 > V_46 ) &&
V_45 < V_37 && V_46 < V_38 ) {
V_45 = F_15 ( 2 * V_45 , V_37 ) ;
V_46 = F_15 ( 2 * V_46 , V_38 ) ;
V_44 -> V_4 = V_45 ;
V_44 -> V_5 = V_46 ;
V_17 = F_13 ( V_9 -> V_33 ,
F_14 ( V_36 ) , V_18 ,
V_48 , NULL , V_40 ) ;
F_8 ( V_32 , L_6 ,
V_44 -> V_4 , V_44 -> V_5 ) ;
if ( V_17 < 0 ) {
F_16 ( V_32 , L_7 , V_17 ) ;
return V_17 ;
}
}
V_49:
V_17 = F_3 ( V_9 , V_10 ) ;
if ( V_17 < 0 )
return V_17 ;
if ( V_47 )
* V_22 = * V_10 ;
else
F_5 ( V_10 , V_22 ) ;
return 0 ;
}
int F_17 ( struct V_35 * V_36 ,
struct V_1 * V_10 , struct V_1 * V_22 ,
struct V_43 * V_44 ,
unsigned int * V_4 , unsigned int * V_5 ,
bool V_41 , unsigned int V_50 )
{
struct V_31 * V_32 = V_36 -> V_42 ;
struct V_39 V_51 = {
. V_13 = V_14 ,
. V_40 = * V_44 ,
} ;
struct V_43 * V_52 = & V_51 . V_40 ;
unsigned int V_53 , V_54 ;
int V_17 ;
V_17 = F_11 ( V_36 , V_10 , V_22 , * V_4 , * V_5 ,
& V_51 , V_41 ) ;
if ( V_17 < 0 )
return V_17 ;
F_8 ( V_32 , L_8 ,
V_52 -> V_4 , V_52 -> V_5 ) ;
V_53 = F_18 ( V_10 -> V_4 , V_50 , V_52 -> V_4 ) ;
V_54 = F_18 ( V_10 -> V_5 , V_50 , V_52 -> V_5 ) ;
V_44 -> V_4 = V_52 -> V_4 ;
V_44 -> V_5 = V_52 -> V_5 ;
V_44 -> V_55 = V_52 -> V_55 ;
* V_4 = F_19 ( V_22 -> V_4 , V_50 , V_53 ) ;
* V_5 = F_19 ( V_22 -> V_5 , V_50 , V_54 ) ;
F_8 ( V_32 , L_9 , * V_4 , * V_5 ) ;
return 0 ;
}
void F_20 ( struct V_35 * V_36 ,
struct V_1 * V_10 , struct V_1 * V_22 ,
const struct V_56 * V_57 , struct V_43 * V_44 ,
unsigned int V_50 )
{
struct V_31 * V_32 = V_36 -> V_42 ;
unsigned int V_54 , V_53 ;
if ( V_22 -> V_4 == V_10 -> V_4 &&
V_22 -> V_5 == V_10 -> V_5 ) {
V_44 -> V_4 = V_57 -> V_4 ;
V_44 -> V_5 = V_57 -> V_5 ;
return;
}
F_8 ( V_32 , L_10 ,
V_22 -> V_4 , V_22 -> V_5 ,
V_22 -> V_6 , V_22 -> V_7 ) ;
V_53 = F_18 ( V_22 -> V_4 , V_50 , V_57 -> V_4 ) ;
V_54 = F_18 ( V_22 -> V_5 , V_50 , V_57 -> V_5 ) ;
F_8 ( V_32 , L_11 , V_53 , V_54 ) ;
V_44 -> V_4 = F_19 ( V_10 -> V_4 , V_50 , V_53 ) ;
V_44 -> V_5 = F_19 ( V_10 -> V_5 , V_50 , V_54 ) ;
}
