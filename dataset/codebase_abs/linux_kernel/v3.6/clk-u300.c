static void F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
T_1 V_4 ;
if ( ! V_2 -> V_5 )
return;
F_2 ( & V_6 , V_3 ) ;
V_4 = F_3 ( V_2 -> V_5 ) ;
V_4 |= F_4 ( V_2 -> V_7 ) ;
F_5 ( V_4 , V_2 -> V_5 ) ;
F_6 ( & V_6 , V_3 ) ;
V_2 -> V_8 = true ;
}
static void F_7 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
T_1 V_4 ;
if ( ! V_2 -> V_5 )
return;
F_2 ( & V_6 , V_3 ) ;
V_4 = F_3 ( V_2 -> V_5 ) ;
V_4 &= ~ F_4 ( V_2 -> V_7 ) ;
F_5 ( V_4 , V_2 -> V_5 ) ;
F_6 ( & V_6 , V_3 ) ;
V_2 -> V_8 = false ;
}
static int F_8 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = F_9 ( V_10 ) ;
if ( V_2 -> V_8 )
F_7 ( V_2 ) ;
return 0 ;
}
static void F_10 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = F_9 ( V_10 ) ;
if ( V_2 -> V_11 == V_12 )
return;
if ( ! V_2 -> V_8 )
F_1 ( V_2 ) ;
}
static int F_11 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = F_9 ( V_10 ) ;
if ( V_2 -> V_13 )
return 0 ;
if ( V_2 -> V_11 == 0xFFFFU )
return 0 ;
F_5 ( V_2 -> V_11 , V_14 + V_15 ) ;
return 0 ;
}
static void F_12 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = F_9 ( V_10 ) ;
if ( V_2 -> V_13 )
return;
if ( V_2 -> V_11 == 0xFFFFU )
return;
if ( V_2 -> V_11 == V_12 )
return;
F_5 ( V_2 -> V_11 , V_14 + V_16 ) ;
}
static int F_13 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = F_9 ( V_10 ) ;
T_1 V_4 ;
if ( ! V_2 -> V_17 )
return 1 ;
V_4 = F_3 ( V_2 -> V_17 ) ;
V_4 &= F_4 ( V_2 -> V_18 ) ;
return V_4 ? 1 : 0 ;
}
static T_1 F_14 ( void )
{
T_1 V_4 ;
V_4 = F_3 ( V_14 + V_19 ) ;
V_4 &= V_20 ;
return V_4 ;
}
static unsigned long
F_15 ( struct V_9 * V_10 ,
unsigned long V_21 )
{
struct V_1 * V_2 = F_9 ( V_10 ) ;
T_1 V_22 = F_14 () ;
switch( V_2 -> V_11 ) {
case V_23 :
case V_24 :
case V_25 :
case V_26 :
case V_27 :
switch( V_22 ) {
case V_28 :
case V_29 :
return 13000000 ;
default:
return V_21 ;
}
case V_30 :
case V_31 :
case V_32 :
switch( V_22 ) {
case V_28 :
case V_29 :
return 6500000 ;
case V_33 :
return 26000000 ;
default:
return V_21 ;
}
case V_34 :
case V_35 :
switch( V_22 ) {
case V_28 :
case V_29 :
return 13000000 ;
case V_33 :
return 52000000 ;
default:
return 104000000 ;
}
case V_36 :
switch( V_22 ) {
case V_28 :
case V_29 :
return 13000000 ;
case V_33 :
return 52000000 ;
case V_37 :
return 104000000 ;
default:
return V_21 ;
}
default:
return V_21 ;
}
}
static long
F_16 ( struct V_9 * V_10 , unsigned long V_38 ,
unsigned long * V_39 )
{
struct V_1 * V_2 = F_9 ( V_10 ) ;
if ( V_2 -> V_11 != V_36 )
return * V_39 ;
if ( V_38 <= 13000000 )
return 13000000 ;
if ( V_38 <= 52000000 )
return 52000000 ;
if ( V_38 <= 104000000 )
return 104000000 ;
return 208000000 ;
}
static int F_17 ( struct V_9 * V_10 , unsigned long V_38 ,
unsigned long V_21 )
{
struct V_1 * V_2 = F_9 ( V_10 ) ;
T_1 V_4 ;
if ( V_2 -> V_11 != V_36 )
return - V_40 ;
switch ( V_38 ) {
case 13000000 :
V_4 = V_28 ;
break;
case 52000000 :
V_4 = V_33 ;
break;
case 104000000 :
V_4 = V_37 ;
break;
case 208000000 :
V_4 = V_41 ;
break;
default:
return - V_40 ;
}
V_4 |= F_3 ( V_14 + V_19 ) &
~ V_20 ;
F_5 ( V_4 , V_14 + V_19 ) ;
return 0 ;
}
static struct V_42 * T_2
F_18 ( struct V_43 * V_44 , const char * V_45 ,
const char * V_46 , unsigned long V_47 ,
bool V_13 ,
void T_3 * V_5 , T_4 V_7 ,
void T_3 * V_17 , T_4 V_18 ,
T_1 V_11 )
{
struct V_42 * V_42 ;
struct V_1 * V_2 ;
struct V_48 V_49 ;
V_2 = F_19 ( sizeof( struct V_1 ) , V_50 ) ;
if ( ! V_2 ) {
F_20 ( L_1 ,
V_45 ) ;
return F_21 ( - V_51 ) ;
}
V_49 . V_45 = V_45 ;
V_49 . V_52 = & V_53 ;
V_49 . V_47 = V_47 ;
V_49 . V_54 = ( V_46 ? & V_46 : NULL ) ;
V_49 . V_55 = ( V_46 ? 1 : 0 ) ;
V_2 -> V_10 . V_49 = & V_49 ;
V_2 -> V_13 = V_13 ;
V_2 -> V_8 = true ;
V_2 -> V_5 = V_5 ;
V_2 -> V_7 = V_7 ;
V_2 -> V_17 = V_17 ;
V_2 -> V_18 = V_18 ;
V_2 -> V_11 = V_11 ;
V_42 = F_22 ( V_44 , & V_2 -> V_10 ) ;
if ( F_23 ( V_42 ) )
F_24 ( V_2 ) ;
return V_42 ;
}
static int F_25 ( struct V_9 * V_10 )
{
struct V_56 * V_57 = F_26 ( V_10 ) ;
T_1 V_4 ;
if ( ! V_57 -> V_58 ) {
F_5 ( 0x0054U , V_14 + V_59 ) ;
V_4 = F_3 ( V_14 + V_60 ) ;
V_4 &= ~ V_61 ;
V_4 &= ~ V_62 ;
F_5 ( V_4 , V_14 + V_60 ) ;
} else {
V_4 = F_3 ( V_14 + V_60 ) ;
V_4 &= ~ V_61 ;
V_4 |= V_62 ;
F_5 ( V_4 , V_14 + V_60 ) ;
}
return 0 ;
}
static unsigned long
F_27 ( struct V_9 * V_10 ,
unsigned long V_21 )
{
T_1 V_22 = F_14 () ;
switch ( V_22 ) {
case V_28 :
return 13000000 ;
case V_29 :
case V_33 :
case V_37 :
case V_41 :
{
T_1 V_4 = F_3 ( V_14 + V_59 ) &
V_63 ;
switch ( V_4 ) {
case 0x0054 :
return 18900000 ;
case 0x0044 :
return 20800000 ;
case 0x0043 :
return 23100000 ;
case 0x0033 :
return 26000000 ;
case 0x0032 :
return 29700000 ;
case 0x0022 :
return 34700000 ;
case 0x0021 :
return 41600000 ;
case 0x0011 :
return 52000000 ;
case 0x0000 :
return 104000000 ;
default:
break;
}
}
default:
break;
}
return V_21 ;
}
static long
F_28 ( struct V_9 * V_10 , unsigned long V_38 ,
unsigned long * V_39 )
{
if ( V_38 <= 18900000 )
return 18900000 ;
if ( V_38 <= 20800000 )
return 20800000 ;
if ( V_38 <= 23100000 )
return 23100000 ;
if ( V_38 <= 26000000 )
return 26000000 ;
if ( V_38 <= 29700000 )
return 29700000 ;
if ( V_38 <= 34700000 )
return 34700000 ;
if ( V_38 <= 41600000 )
return 41600000 ;
return 52000000 ;
}
static int F_29 ( struct V_9 * V_10 , unsigned long V_38 ,
unsigned long V_21 )
{
T_1 V_4 ;
T_1 V_64 ;
switch ( V_38 ) {
case 18900000 :
V_4 = 0x0054 ;
break;
case 20800000 :
V_4 = 0x0044 ;
break;
case 23100000 :
V_4 = 0x0043 ;
break;
case 26000000 :
V_4 = 0x0033 ;
break;
case 29700000 :
V_4 = 0x0032 ;
break;
case 34700000 :
V_4 = 0x0022 ;
break;
case 41600000 :
V_4 = 0x0021 ;
break;
case 52000000 :
V_4 = 0x0011 ;
break;
case 104000000 :
V_4 = 0x0000 ;
break;
default:
return - V_40 ;
}
V_64 = F_3 ( V_14 + V_59 ) &
~ V_63 ;
F_5 ( V_64 | V_4 , V_14 + V_59 ) ;
return 0 ;
}
static struct V_42 * T_2
F_30 ( struct V_43 * V_44 , const char * V_45 ,
const char * V_46 , bool V_58 )
{
struct V_42 * V_42 ;
struct V_56 * V_57 ;
struct V_48 V_49 ;
V_57 = F_19 ( sizeof( struct V_56 ) , V_50 ) ;
if ( ! V_57 ) {
F_20 ( L_2 ,
V_45 ) ;
return F_21 ( - V_51 ) ;
}
V_49 . V_45 = L_3 ;
V_49 . V_52 = & V_65 ;
V_49 . V_47 = 0 ;
V_49 . V_54 = ( V_46 ? & V_46 : NULL ) ;
V_49 . V_55 = ( V_46 ? 1 : 0 ) ;
V_57 -> V_10 . V_49 = & V_49 ;
V_57 -> V_58 = V_58 ;
V_42 = F_22 ( V_44 , & V_57 -> V_10 ) ;
if ( F_23 ( V_42 ) )
F_24 ( V_57 ) ;
return V_42 ;
}
void T_2 F_31 ( void T_3 * V_66 )
{
T_1 V_4 ;
struct V_42 * V_42 ;
V_14 = V_66 ;
V_4 = F_3 ( V_14 + V_19 ) ;
V_4 &= ~ V_20 ;
F_5 ( V_4 , V_14 + V_19 ) ;
while ( ! ( F_3 ( V_14 + V_67 ) &
V_68 ) ) ;
V_4 = F_3 ( V_14 + V_69 ) ;
V_4 |= V_70 ;
F_5 ( V_4 , V_14 + V_69 ) ;
V_42 = F_32 ( NULL , L_4 , NULL ,
V_71 , 32768 ) ;
F_33 ( V_42 , NULL , L_5 ) ;
V_42 = F_32 ( NULL , L_6 , NULL ,
V_71 , 13000000 ) ;
V_42 = F_32 ( NULL , L_7 , NULL ,
V_71 , 208000000 ) ;
V_42 = F_34 ( NULL , L_8 , L_7 ,
0 , 1 , 1 ) ;
V_42 = F_34 ( NULL , L_9 , L_7 ,
0 , 1 , 2 ) ;
V_42 = F_34 ( NULL , L_10 , L_7 ,
0 , 1 , 4 ) ;
V_42 = F_34 ( NULL , L_11 , L_10 ,
0 , 1 , 2 ) ;
V_42 = F_18 ( NULL , L_12 , L_8 , 0 , true ,
V_14 + V_72 , 3 ,
V_14 + V_73 , 3 ,
V_36 ) ;
V_42 = F_18 ( NULL , L_13 , L_10 , 0 , true ,
V_14 + V_72 , 4 ,
V_14 + V_73 , 4 ,
V_30 ) ;
F_33 ( V_42 , NULL , L_14 ) ;
V_42 = F_18 ( NULL , L_15 , L_10 , 0 , false ,
V_14 + V_72 , 6 ,
V_14 + V_73 , 6 ,
V_31 ) ;
F_33 ( V_42 , NULL , L_16 ) ;
V_42 = F_18 ( NULL , L_17 , L_10 , 0 , true ,
V_14 + V_72 , 8 ,
V_14 + V_73 , 8 ,
V_32 ) ;
F_33 ( V_42 , NULL , L_18 ) ;
V_42 = F_18 ( NULL , L_19 , L_9 , 0 , false ,
V_14 + V_72 , 9 ,
V_14 + V_73 , 9 ,
V_34 ) ;
F_33 ( V_42 , NULL , L_20 ) ;
V_42 = F_18 ( NULL , L_21 , L_10 , 0 , true ,
V_14 + V_72 , 10 ,
V_14 + V_73 , 10 ,
V_74 ) ;
V_42 = F_18 ( NULL , L_22 , L_21 , 0 , false ,
V_14 + V_72 , 12 ,
V_14 + V_73 , 12 ,
0xFFFFU ) ;
F_33 ( V_42 , NULL , L_23 ) ;
V_42 = F_18 ( NULL , L_24 , L_21 , 0 , false ,
V_14 + V_72 , 5 ,
V_14 + V_73 , 5 ,
V_35 ) ;
F_33 ( V_42 , NULL , L_25 ) ;
V_42 = F_18 ( NULL , L_26 , L_11 , 0 , true ,
V_14 + V_75 , 0 ,
V_14 + V_76 , 0 ,
V_23 ) ;
V_42 = F_18 ( NULL , L_27 , L_26 , 0 , false ,
V_14 + V_75 , 1 ,
V_14 + V_76 , 1 ,
V_24 ) ;
F_33 ( V_42 , NULL , L_28 ) ;
V_42 = F_18 ( NULL , L_29 , L_26 , 0 , false ,
V_14 + V_75 , 2 ,
V_14 + V_76 , 2 ,
V_25 ) ;
F_33 ( V_42 , NULL , L_30 ) ;
V_42 = F_18 ( NULL , L_31 , L_26 , 0 , false ,
V_14 + V_75 , 5 ,
V_14 + V_76 , 5 ,
V_26 ) ;
F_33 ( V_42 , L_32 , L_33 ) ;
V_42 = F_18 ( NULL , L_34 , L_26 , 0 , false ,
V_14 + V_75 , 6 ,
V_14 + V_76 , 6 ,
V_27 ) ;
F_33 ( V_42 , NULL , L_35 ) ;
F_33 ( V_42 , L_32 , L_35 ) ;
V_42 = F_18 ( NULL , L_36 , L_6 , 0 , true ,
V_14 + V_77 , 0 ,
V_14 + V_78 , 0 ,
V_79 ) ;
V_42 = F_18 ( NULL , L_37 , L_36 , 0 , false ,
V_14 + V_77 , 1 ,
V_14 + V_78 , 1 ,
V_12 ) ;
F_33 ( V_42 , NULL , L_38 ) ;
F_33 ( V_42 , L_32 , L_38 ) ;
V_42 = F_18 ( NULL , L_39 , L_36 , 0 , false ,
V_14 + V_77 , 4 ,
V_14 + V_78 , 4 ,
V_80 ) ;
F_33 ( V_42 , NULL , L_40 ) ;
V_42 = F_18 ( NULL , L_41 , L_36 , 0 , false ,
V_14 + V_77 , 5 ,
V_14 + V_78 , 6 ,
V_81 ) ;
F_33 ( V_42 , NULL , L_42 ) ;
V_42 = F_18 ( NULL , L_43 , L_36 , 0 , true ,
V_14 + V_77 , 6 ,
NULL , 0 , 0xFFFFU ) ;
F_33 ( V_42 , NULL , L_44 ) ;
V_42 = F_18 ( NULL , L_45 , L_36 , 0 , false ,
V_14 + V_77 , 7 ,
V_14 + V_78 , 7 ,
V_82 ) ;
F_33 ( V_42 , NULL , L_46 ) ;
V_42 = F_18 ( NULL , L_47 , L_36 , 0 , false ,
V_14 + V_77 , 8 ,
V_14 + V_78 , 8 ,
V_83 ) ;
F_33 ( V_42 , NULL , L_48 ) ;
V_42 = F_30 ( NULL , L_49 , L_31 , false ) ;
F_33 ( V_42 , NULL , L_33 ) ;
}
