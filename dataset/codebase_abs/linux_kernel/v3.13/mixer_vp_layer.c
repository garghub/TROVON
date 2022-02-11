static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 ) ;
F_3 ( V_2 ) ;
}
static void F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_1 V_5 [ 2 ] = { 0 , 0 } ;
T_1 V_6 [ 2 ] = { 0 , 0 } ;
if ( V_4 == NULL ) {
F_5 ( V_2 -> V_7 , V_5 , V_6 ) ;
return;
}
V_5 [ 0 ] = F_6 ( & V_4 -> V_8 , 0 ) ;
if ( V_2 -> V_9 -> V_10 == 2 ) {
V_6 [ 0 ] = F_6 ( & V_4 -> V_8 , 1 ) ;
} else {
V_6 [ 0 ] = V_5 [ 0 ] + F_7 (
& V_2 -> V_9 -> V_11 [ 0 ] , V_2 -> V_12 . V_13 . V_14 ,
V_2 -> V_12 . V_13 . V_15 ) ;
}
if ( V_2 -> V_9 -> V_16 & V_17 ) {
V_5 [ 1 ] = V_5 [ 0 ] + 0x40 ;
V_6 [ 1 ] = V_6 [ 0 ] + 0x40 ;
} else {
V_5 [ 1 ] = V_5 [ 0 ] + V_2 -> V_12 . V_13 . V_14 ;
V_6 [ 1 ] = V_6 [ 0 ] ;
}
F_5 ( V_2 -> V_7 , V_5 , V_6 ) ;
}
static void F_8 ( struct V_1 * V_2 , int V_18 )
{
F_9 ( V_2 -> V_7 , V_18 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
F_11 ( V_2 -> V_7 , V_2 -> V_9 , & V_2 -> V_12 ) ;
}
static inline unsigned int F_12 ( unsigned int V_19 ,
unsigned int V_20 , unsigned int V_21 , unsigned int V_22 )
{
unsigned int V_23 ;
if ( V_22 & V_24 )
return 0 ;
V_23 = V_19 - F_13 ( V_19 , V_20 / 2 ) ;
return F_13 ( V_23 , V_21 - V_20 ) ;
}
static void F_14 ( struct V_1 * V_2 ,
enum V_25 V_26 , unsigned long V_22 )
{
struct V_27 * V_12 = & V_2 -> V_12 ;
struct V_28 * V_13 = & V_12 -> V_13 ;
struct V_28 * V_29 = & V_12 -> V_29 ;
unsigned long V_30 , V_31 ;
switch ( V_26 ) {
case V_32 :
case V_33 :
V_30 = V_29 -> V_34 + V_29 -> V_35 / 2 ;
V_31 = V_29 -> V_36 + V_29 -> V_37 / 2 ;
V_29 -> V_35 = F_15 ( V_29 -> V_35 , 8U , 16 * V_13 -> V_14 ) ;
V_29 -> V_37 = F_15 ( V_29 -> V_37 , 1U , 16 * V_13 -> V_15 ) ;
V_29 -> V_34 = F_12 ( V_30 , V_29 -> V_35 ,
V_29 -> V_14 , V_22 ) ;
V_29 -> V_36 = F_12 ( V_31 , V_29 -> V_37 ,
V_29 -> V_15 , V_22 ) ;
V_22 = 0 ;
case V_38 :
V_30 = V_13 -> V_34 + V_13 -> V_35 / 2 ;
V_31 = V_13 -> V_36 + V_13 -> V_37 / 2 ;
V_13 -> V_35 = F_15 ( V_13 -> V_35 , F_16 ( V_29 -> V_35 / 16 , 4 ) ,
V_29 -> V_35 * 4 ) ;
V_13 -> V_37 = F_15 ( V_13 -> V_37 , F_16 ( V_29 -> V_37 / 16 , 4 ) ,
V_29 -> V_37 * 4 ) ;
V_13 -> V_35 = F_15 ( V_13 -> V_35 , 32U , 2047U ) ;
V_13 -> V_37 = F_15 ( V_13 -> V_37 , 4U , 2047U ) ;
V_13 -> V_34 = F_12 ( V_30 , V_13 -> V_35 ,
V_13 -> V_14 , V_22 ) ;
V_13 -> V_36 = F_12 ( V_31 , V_13 -> V_37 ,
V_13 -> V_15 , V_22 ) ;
V_12 -> V_39 = ( V_13 -> V_35 << 16 ) / V_29 -> V_35 ;
V_12 -> V_40 = ( V_13 -> V_37 << 16 ) / V_29 -> V_37 ;
case V_41 :
V_13 -> V_14 = F_15 ( V_13 -> V_14 ,
F_17 ( V_13 -> V_35 + V_13 -> V_34 , 8 ) , 8192U ) ;
V_13 -> V_15 = F_15 ( V_13 -> V_15 ,
V_13 -> V_37 + V_13 -> V_36 , 8192U ) ;
}
}
struct V_1 * F_18 ( struct V_42 * V_7 , int V_43 )
{
struct V_1 * V_2 ;
int V_44 ;
struct V_45 V_46 = {
. V_47 = F_1 ,
. V_48 = F_4 ,
. V_49 = F_8 ,
. V_50 = F_10 ,
. V_51 = F_14 ,
} ;
char V_52 [ 32 ] ;
sprintf ( V_52 , L_1 , V_43 ) ;
V_2 = F_19 ( V_7 , V_43 , V_52 , & V_46 ) ;
if ( V_2 == NULL ) {
F_20 ( V_7 , L_2 , V_43 ) ;
goto V_53;
}
V_2 -> V_54 = V_55 ;
V_2 -> V_56 = F_21 ( V_55 ) ;
V_44 = F_22 ( V_2 ) ;
if ( V_44 )
goto V_57;
return V_2 ;
V_57:
F_3 ( V_2 ) ;
V_53:
return NULL ;
}
