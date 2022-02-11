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
V_5 [ 0 ] = F_6 ( & V_4 -> V_8 . V_9 , 0 ) ;
if ( V_2 -> V_10 -> V_11 == 2 ) {
V_6 [ 0 ] =
F_6 ( & V_4 -> V_8 . V_9 , 1 ) ;
} else {
V_6 [ 0 ] = V_5 [ 0 ] + F_7 (
& V_2 -> V_10 -> V_12 [ 0 ] , V_2 -> V_13 . V_14 . V_15 ,
V_2 -> V_13 . V_14 . V_16 ) ;
}
if ( V_2 -> V_10 -> V_17 & V_18 ) {
V_5 [ 1 ] = V_5 [ 0 ] + 0x40 ;
V_6 [ 1 ] = V_6 [ 0 ] + 0x40 ;
} else {
V_5 [ 1 ] = V_5 [ 0 ] + V_2 -> V_13 . V_14 . V_15 ;
V_6 [ 1 ] = V_6 [ 0 ] ;
}
F_5 ( V_2 -> V_7 , V_5 , V_6 ) ;
}
static void F_8 ( struct V_1 * V_2 , int V_19 )
{
F_9 ( V_2 -> V_7 , V_19 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
F_11 ( V_2 -> V_7 , V_2 -> V_10 , & V_2 -> V_13 ) ;
}
static inline unsigned int F_12 ( unsigned int V_20 ,
unsigned int V_21 , unsigned int V_22 , unsigned int V_23 )
{
unsigned int V_24 ;
if ( V_23 & V_25 )
return 0 ;
V_24 = V_20 - F_13 ( V_20 , V_21 / 2 ) ;
return F_13 ( V_24 , V_22 - V_21 ) ;
}
static void F_14 ( struct V_1 * V_2 ,
enum V_26 V_27 , unsigned long V_23 )
{
struct V_28 * V_13 = & V_2 -> V_13 ;
struct V_29 * V_14 = & V_13 -> V_14 ;
struct V_29 * V_30 = & V_13 -> V_30 ;
unsigned long V_31 , V_32 ;
switch ( V_27 ) {
case V_33 :
case V_34 :
V_31 = V_30 -> V_35 + V_30 -> V_36 / 2 ;
V_32 = V_30 -> V_37 + V_30 -> V_38 / 2 ;
V_30 -> V_36 = F_15 ( V_30 -> V_36 , 8U , 16 * V_14 -> V_15 ) ;
V_30 -> V_38 = F_15 ( V_30 -> V_38 , 1U , 16 * V_14 -> V_16 ) ;
V_30 -> V_35 = F_12 ( V_31 , V_30 -> V_36 ,
V_30 -> V_15 , V_23 ) ;
V_30 -> V_37 = F_12 ( V_32 , V_30 -> V_38 ,
V_30 -> V_16 , V_23 ) ;
V_23 = 0 ;
case V_39 :
V_31 = V_14 -> V_35 + V_14 -> V_36 / 2 ;
V_32 = V_14 -> V_37 + V_14 -> V_38 / 2 ;
V_14 -> V_36 = F_15 ( V_14 -> V_36 , F_16 ( V_30 -> V_36 / 16 , 4 ) ,
V_30 -> V_36 * 4 ) ;
V_14 -> V_38 = F_15 ( V_14 -> V_38 , F_16 ( V_30 -> V_38 / 16 , 4 ) ,
V_30 -> V_38 * 4 ) ;
V_14 -> V_36 = F_15 ( V_14 -> V_36 , 32U , 2047U ) ;
V_14 -> V_38 = F_15 ( V_14 -> V_38 , 4U , 2047U ) ;
V_14 -> V_35 = F_12 ( V_31 , V_14 -> V_36 ,
V_14 -> V_15 , V_23 ) ;
V_14 -> V_37 = F_12 ( V_32 , V_14 -> V_38 ,
V_14 -> V_16 , V_23 ) ;
V_13 -> V_40 = ( V_14 -> V_36 << 16 ) / V_30 -> V_36 ;
V_13 -> V_41 = ( V_14 -> V_38 << 16 ) / V_30 -> V_38 ;
case V_42 :
V_14 -> V_15 = F_15 ( V_14 -> V_15 ,
F_17 ( V_14 -> V_36 + V_14 -> V_35 , 8 ) , 8192U ) ;
V_14 -> V_16 = F_15 ( V_14 -> V_16 ,
V_14 -> V_38 + V_14 -> V_37 , 8192U ) ;
}
}
struct V_1 * F_18 ( struct V_43 * V_7 , int V_44 )
{
struct V_1 * V_2 ;
int V_45 ;
const struct V_46 V_47 = {
. V_48 = F_1 ,
. V_49 = F_4 ,
. V_50 = F_8 ,
. V_51 = F_10 ,
. V_52 = F_14 ,
} ;
char V_53 [ 32 ] ;
sprintf ( V_53 , L_1 , V_44 ) ;
V_2 = F_19 ( V_7 , V_44 , V_53 , & V_47 ) ;
if ( V_2 == NULL ) {
F_20 ( V_7 , L_2 , V_44 ) ;
goto V_54;
}
V_2 -> V_55 = V_56 ;
V_2 -> V_57 = F_21 ( V_56 ) ;
V_45 = F_22 ( V_2 ) ;
if ( V_45 )
goto V_58;
return V_2 ;
V_58:
F_3 ( V_2 ) ;
V_54:
return NULL ;
}
