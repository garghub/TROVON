void F_1 ( struct V_1 * V_2 , T_1 * V_3 ,
T_2 V_4 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
unsigned int V_9 ;
unsigned int V_10 ;
int V_11 = 0 ;
int V_12 ;
F_2 ( L_1 , V_2 ,
V_3 , V_4 ) ;
V_6 = V_2 -> V_13 ;
if ( V_6 == NULL ) {
F_2 ( L_2 ) ;
return;
}
V_8 = V_6 -> V_8 ;
if ( V_8 == NULL ) {
F_2 ( L_3 ) ;
return;
}
V_10 = V_8 -> V_14 >> 3 ;
if ( V_10 == 0 ) {
F_2 ( L_4 ) ;
return;
}
V_12 = V_4 / V_10 ;
if ( V_12 == 0 ) {
F_2 ( L_5 , V_15 ) ;
return;
}
if ( V_8 -> V_16 == NULL ) {
F_2 ( L_6 ) ;
return;
}
V_9 = V_2 -> V_17 ;
if ( V_9 + V_12 >= V_8 -> V_18 ) {
unsigned int V_19 =
V_8 -> V_18 - V_9 ;
memcpy ( V_8 -> V_16 + V_9 * V_10 , V_3 ,
V_19 * V_10 ) ;
memcpy ( V_8 -> V_16 , V_3 + V_19 * V_10 ,
V_12 * V_10 - V_19 * V_10 ) ;
} else {
memcpy ( V_8 -> V_16 + V_9 * V_10 , V_3 ,
V_12 * V_10 ) ;
}
F_3 ( V_6 ) ;
V_2 -> V_17 += V_12 ;
if ( V_2 -> V_17 >=
V_8 -> V_18 )
V_2 -> V_17 -=
V_8 -> V_18 ;
V_2 -> V_20 += V_12 ;
if ( V_2 -> V_20 >=
V_8 -> V_21 ) {
V_2 -> V_20 -=
V_8 -> V_21 ;
V_11 = 1 ;
}
F_4 ( V_6 ) ;
if ( V_11 )
F_5 ( V_6 ) ;
}
static int F_6 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_7 ( V_6 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_22 * V_23 = V_2 -> V_23 ;
struct V_24 * V_25 = F_8 ( V_23 ) ;
struct V_26 * V_27 ;
struct V_28 V_29 ;
int V_30 ;
F_9 ( V_2 ) ;
V_27 = & V_25 -> V_31 [ V_32 ] ;
V_29 . V_25 = V_25 ;
V_29 . type = V_27 -> type ;
V_29 . V_33 = V_25 -> V_33 ++ ;
if ( F_10 ( & V_29 , V_29 . type ) ) {
F_11 ( V_2 ) ;
return - V_34 ;
}
if ( F_12 ( V_35 , & V_27 -> V_36 ) ||
F_13 ( V_37 , & V_27 -> V_36 ) ) {
F_11 ( V_2 ) ;
return 0 ;
}
V_8 -> V_38 = V_39 ;
F_14 ( V_8 , V_40 ) ;
V_2 -> V_13 = V_6 ;
V_8 -> V_41 = V_25 ;
V_25 -> V_42 = F_1 ;
F_15 ( V_37 , & V_27 -> V_36 ) ;
V_30 = F_16 ( V_27 ) ;
F_11 ( V_2 ) ;
return 0 ;
}
static int F_17 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_7 ( V_6 ) ;
struct V_22 * V_23 = V_2 -> V_23 ;
struct V_24 * V_25 = F_8 ( V_23 ) ;
struct V_26 * V_27 ;
int V_30 ;
F_9 ( V_2 ) ;
V_27 = & V_25 -> V_31 [ V_32 ] ;
V_30 = F_18 ( V_27 , 0 ) ;
F_19 ( V_37 , & V_27 -> V_36 ) ;
F_20 ( V_27 ) ;
V_25 -> V_42 = NULL ;
F_11 ( V_2 ) ;
return 0 ;
}
static int F_21 ( struct V_5 * V_6 ,
unsigned int V_43 , void * V_44 )
{
struct V_1 * V_2 = F_7 ( V_6 ) ;
int V_30 ;
F_9 ( V_2 ) ;
V_30 = F_22 ( V_6 , V_43 , V_44 ) ;
F_11 ( V_2 ) ;
return V_30 ;
}
static int F_23 ( struct V_5 * V_45 ,
T_2 V_46 )
{
struct V_7 * V_8 = V_45 -> V_8 ;
F_2 ( L_7 ) ;
if ( V_8 -> V_16 ) {
if ( V_8 -> V_47 > V_46 )
return 0 ;
F_24 ( V_8 -> V_16 ) ;
}
V_8 -> V_16 = F_25 ( V_46 ) ;
if ( ! V_8 -> V_16 )
return - V_48 ;
V_8 -> V_47 = V_46 ;
return 0 ;
}
static int F_26 ( struct V_5 * V_6 ,
struct V_49 * V_50 )
{
int V_30 ;
F_2 ( L_8 , V_15 ) ;
V_30 = F_23 ( V_6 ,
F_27 ( V_50 ) ) ;
return 0 ;
}
static int F_28 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_7 ( V_6 ) ;
unsigned long V_51 ;
F_29 ( & V_2 -> V_52 , V_51 ) ;
if ( V_6 -> V_8 -> V_16 ) {
F_2 ( L_9 ) ;
F_24 ( V_6 -> V_8 -> V_16 ) ;
V_6 -> V_8 -> V_16 = NULL ;
}
F_30 ( & V_2 -> V_52 , V_51 ) ;
return 0 ;
}
static int F_31 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_7 ( V_6 ) ;
V_2 -> V_17 = 0 ;
V_2 -> V_20 = 0 ;
return 0 ;
}
static int F_32 ( struct V_5 * V_6 , int V_43 )
{
return 0 ;
}
static
T_3 F_33 ( struct V_5 * V_6 )
{
unsigned long V_51 ;
T_3 V_53 ;
struct V_1 * V_2 = F_7 ( V_6 ) ;
F_29 ( & V_2 -> V_52 , V_51 ) ;
V_53 = V_2 -> V_17 ;
F_30 ( & V_2 -> V_52 , V_51 ) ;
return V_53 ;
}
static struct V_54 * F_34 ( struct V_5 * V_45 ,
unsigned long V_55 )
{
void * V_56 = V_45 -> V_8 -> V_16 + V_55 ;
return F_35 ( V_56 ) ;
}
int F_36 ( struct V_1 * V_2 )
{
struct V_57 * V_58 ;
struct V_59 * V_60 = V_2 -> V_60 ;
struct V_22 * V_23 = V_2 -> V_23 ;
struct V_24 * V_25 = F_8 ( V_23 ) ;
int V_30 ;
V_30 = F_37 ( V_60 , L_10 ,
0 ,
0 ,
1 ,
& V_58 ) ;
if ( V_30 ) {
F_38 ( L_11 ,
V_15 , V_30 ) ;
goto V_61;
}
F_39 ( & V_2 -> V_52 ) ;
F_40 ( V_58 , V_62 ,
& V_63 ) ;
V_58 -> V_64 = 0 ;
V_58 -> V_41 = V_2 ;
F_41 ( V_58 -> V_65 , V_25 -> V_66 , sizeof( V_58 -> V_65 ) ) ;
return 0 ;
V_61:
return V_30 ;
}
