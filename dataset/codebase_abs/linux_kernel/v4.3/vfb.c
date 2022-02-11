static void * F_1 ( unsigned long V_1 )
{
void * V_2 ;
unsigned long V_3 ;
V_1 = F_2 ( V_1 ) ;
V_2 = F_3 ( V_1 ) ;
if ( ! V_2 )
return NULL ;
memset ( V_2 , 0 , V_1 ) ;
V_3 = ( unsigned long ) V_2 ;
while ( V_1 > 0 ) {
F_4 ( F_5 ( ( void * ) V_3 ) ) ;
V_3 += V_4 ;
V_1 -= V_4 ;
}
return V_2 ;
}
static void F_6 ( void * V_2 , unsigned long V_1 )
{
unsigned long V_3 ;
if ( ! V_2 )
return;
V_3 = ( unsigned long ) V_2 ;
while ( ( long ) V_1 > 0 ) {
F_7 ( F_5 ( ( void * ) V_3 ) ) ;
V_3 += V_4 ;
V_1 -= V_4 ;
}
F_8 ( V_2 ) ;
}
static T_1 F_9 ( int V_5 , int V_6 )
{
T_1 V_7 ;
V_7 = V_5 * V_6 ;
V_7 = ( V_7 + 31 ) & ~ 31 ;
V_7 >>= 3 ;
return ( V_7 ) ;
}
static int F_10 ( struct V_8 * V_9 ,
struct V_10 * V_11 )
{
T_1 V_12 ;
if ( V_9 -> V_13 & V_14 ) {
V_9 -> V_13 |= V_15 ;
V_9 -> V_16 = V_11 -> V_9 . V_16 ;
V_9 -> V_17 = V_11 -> V_9 . V_17 ;
}
if ( ! V_9 -> V_18 )
V_9 -> V_18 = 1 ;
if ( ! V_9 -> V_19 )
V_9 -> V_19 = 1 ;
if ( V_9 -> V_18 > V_9 -> V_5 )
V_9 -> V_5 = V_9 -> V_18 ;
if ( V_9 -> V_19 > V_9 -> V_20 )
V_9 -> V_20 = V_9 -> V_19 ;
if ( V_9 -> V_21 <= 1 )
V_9 -> V_21 = 1 ;
else if ( V_9 -> V_21 <= 8 )
V_9 -> V_21 = 8 ;
else if ( V_9 -> V_21 <= 16 )
V_9 -> V_21 = 16 ;
else if ( V_9 -> V_21 <= 24 )
V_9 -> V_21 = 24 ;
else if ( V_9 -> V_21 <= 32 )
V_9 -> V_21 = 32 ;
else
return - V_22 ;
if ( V_9 -> V_5 < V_9 -> V_16 + V_9 -> V_18 )
V_9 -> V_5 = V_9 -> V_16 + V_9 -> V_18 ;
if ( V_9 -> V_20 < V_9 -> V_17 + V_9 -> V_19 )
V_9 -> V_20 = V_9 -> V_17 + V_9 -> V_19 ;
V_12 =
F_9 ( V_9 -> V_5 , V_9 -> V_21 ) ;
if ( V_12 * V_9 -> V_20 > V_23 )
return - V_24 ;
switch ( V_9 -> V_21 ) {
case 1 :
case 8 :
V_9 -> V_25 . V_26 = 0 ;
V_9 -> V_25 . V_7 = 8 ;
V_9 -> V_27 . V_26 = 0 ;
V_9 -> V_27 . V_7 = 8 ;
V_9 -> V_28 . V_26 = 0 ;
V_9 -> V_28 . V_7 = 8 ;
V_9 -> V_29 . V_26 = 0 ;
V_9 -> V_29 . V_7 = 0 ;
break;
case 16 :
if ( V_9 -> V_29 . V_7 ) {
V_9 -> V_25 . V_26 = 0 ;
V_9 -> V_25 . V_7 = 5 ;
V_9 -> V_27 . V_26 = 5 ;
V_9 -> V_27 . V_7 = 5 ;
V_9 -> V_28 . V_26 = 10 ;
V_9 -> V_28 . V_7 = 5 ;
V_9 -> V_29 . V_26 = 15 ;
V_9 -> V_29 . V_7 = 1 ;
} else {
V_9 -> V_25 . V_26 = 0 ;
V_9 -> V_25 . V_7 = 5 ;
V_9 -> V_27 . V_26 = 5 ;
V_9 -> V_27 . V_7 = 6 ;
V_9 -> V_28 . V_26 = 11 ;
V_9 -> V_28 . V_7 = 5 ;
V_9 -> V_29 . V_26 = 0 ;
V_9 -> V_29 . V_7 = 0 ;
}
break;
case 24 :
V_9 -> V_25 . V_26 = 0 ;
V_9 -> V_25 . V_7 = 8 ;
V_9 -> V_27 . V_26 = 8 ;
V_9 -> V_27 . V_7 = 8 ;
V_9 -> V_28 . V_26 = 16 ;
V_9 -> V_28 . V_7 = 8 ;
V_9 -> V_29 . V_26 = 0 ;
V_9 -> V_29 . V_7 = 0 ;
break;
case 32 :
V_9 -> V_25 . V_26 = 0 ;
V_9 -> V_25 . V_7 = 8 ;
V_9 -> V_27 . V_26 = 8 ;
V_9 -> V_27 . V_7 = 8 ;
V_9 -> V_28 . V_26 = 16 ;
V_9 -> V_28 . V_7 = 8 ;
V_9 -> V_29 . V_26 = 24 ;
V_9 -> V_29 . V_7 = 8 ;
break;
}
V_9 -> V_25 . V_30 = 0 ;
V_9 -> V_27 . V_30 = 0 ;
V_9 -> V_28 . V_30 = 0 ;
V_9 -> V_29 . V_30 = 0 ;
return 0 ;
}
static int F_11 ( struct V_10 * V_11 )
{
V_11 -> V_31 . V_12 = F_9 ( V_11 -> V_9 . V_5 ,
V_11 -> V_9 . V_21 ) ;
return 0 ;
}
static int F_12 ( T_2 V_32 , T_2 V_25 , T_2 V_27 , T_2 V_28 ,
T_2 V_29 , struct V_10 * V_11 )
{
if ( V_32 >= 256 )
return 1 ;
if ( V_11 -> V_9 . V_33 ) {
V_25 = V_27 = V_28 =
( V_25 * 77 + V_27 * 151 + V_28 * 28 ) >> 8 ;
}
#define F_13 ( T_3 , T_4 ) ((((val)<<(width))+0x7FFF-(val))>>16)
switch ( V_11 -> V_31 . V_34 ) {
case V_35 :
case V_36 :
V_25 = F_13 ( V_25 , V_11 -> V_9 . V_25 . V_7 ) ;
V_27 = F_13 ( V_27 , V_11 -> V_9 . V_27 . V_7 ) ;
V_28 = F_13 ( V_28 , V_11 -> V_9 . V_28 . V_7 ) ;
V_29 = F_13 ( V_29 , V_11 -> V_9 . V_29 . V_7 ) ;
break;
case V_37 :
V_25 = F_13 ( V_25 , 8 ) ;
V_27 = F_13 ( V_27 , 8 ) ;
V_28 = F_13 ( V_28 , 8 ) ;
V_29 = F_13 ( V_29 , 8 ) ;
break;
}
#undef F_13
if ( V_11 -> V_31 . V_34 == V_35 ) {
T_5 V_38 ;
if ( V_32 >= 16 )
return 1 ;
V_38 = ( V_25 << V_11 -> V_9 . V_25 . V_26 ) |
( V_27 << V_11 -> V_9 . V_27 . V_26 ) |
( V_28 << V_11 -> V_9 . V_28 . V_26 ) |
( V_29 << V_11 -> V_9 . V_29 . V_26 ) ;
switch ( V_11 -> V_9 . V_21 ) {
case 8 :
break;
case 16 :
( ( T_5 * ) ( V_11 -> V_39 ) ) [ V_32 ] = V_38 ;
break;
case 24 :
case 32 :
( ( T_5 * ) ( V_11 -> V_39 ) ) [ V_32 ] = V_38 ;
break;
}
return 0 ;
}
return 0 ;
}
static int F_14 ( struct V_8 * V_9 ,
struct V_10 * V_11 )
{
if ( V_9 -> V_13 & V_15 ) {
if ( V_9 -> V_17 >= V_11 -> V_9 . V_20 ||
V_9 -> V_16 )
return - V_22 ;
} else {
if ( V_9 -> V_16 + V_11 -> V_9 . V_18 > V_11 -> V_9 . V_5 ||
V_9 -> V_17 + V_11 -> V_9 . V_19 > V_11 -> V_9 . V_20 )
return - V_22 ;
}
V_11 -> V_9 . V_16 = V_9 -> V_16 ;
V_11 -> V_9 . V_17 = V_9 -> V_17 ;
if ( V_9 -> V_13 & V_15 )
V_11 -> V_9 . V_13 |= V_15 ;
else
V_11 -> V_9 . V_13 &= ~ V_15 ;
return 0 ;
}
static int F_15 ( struct V_10 * V_11 ,
struct V_40 * V_41 )
{
unsigned long V_42 = V_41 -> V_43 ;
unsigned long V_1 = V_41 -> V_44 - V_41 -> V_43 ;
unsigned long V_26 = V_41 -> V_45 << V_46 ;
unsigned long V_47 , V_48 ;
if ( V_41 -> V_45 > ( ~ 0UL >> V_46 ) )
return - V_22 ;
if ( V_1 > V_11 -> V_31 . V_49 )
return - V_22 ;
if ( V_26 > V_11 -> V_31 . V_49 - V_1 )
return - V_22 ;
V_48 = ( unsigned long ) V_11 -> V_31 . V_50 + V_26 ;
while ( V_1 > 0 ) {
V_47 = F_16 ( ( void * ) V_48 ) ;
if ( F_17 ( V_41 , V_42 , V_47 , V_4 , V_51 ) ) {
return - V_52 ;
}
V_42 += V_4 ;
V_48 += V_4 ;
if ( V_1 > V_4 )
V_1 -= V_4 ;
else
V_1 = 0 ;
}
return 0 ;
}
static int T_6 F_18 ( char * V_53 )
{
char * V_54 ;
V_55 = 0 ;
if ( ! V_53 )
return 1 ;
V_55 = 1 ;
if ( ! * V_53 )
return 1 ;
while ( ( V_54 = F_19 ( & V_53 , L_1 ) ) != NULL ) {
if ( ! * V_54 )
continue;
if ( ! strcmp ( V_54 , L_2 ) )
V_55 = 0 ;
}
return 1 ;
}
static int F_20 ( struct V_56 * V_57 )
{
struct V_10 * V_11 ;
int V_58 = - V_24 ;
if ( ! ( V_59 = F_1 ( V_23 ) ) )
return V_58 ;
V_11 = F_21 ( sizeof( T_5 ) * 256 , & V_57 -> V_57 ) ;
if ( ! V_11 )
goto V_60;
V_11 -> V_61 = ( char V_62 * ) V_59 ;
V_11 -> V_63 = & V_64 ;
V_58 = F_22 ( & V_11 -> V_9 , V_11 , NULL ,
NULL , 0 , NULL , 8 ) ;
if ( ! V_58 || ( V_58 == 4 ) )
V_11 -> V_9 = V_65 ;
V_66 . V_50 = ( unsigned long ) V_59 ;
V_66 . V_49 = V_23 ;
V_11 -> V_31 = V_66 ;
V_11 -> V_39 = V_11 -> V_67 ;
V_11 -> V_67 = NULL ;
V_11 -> V_68 = V_69 ;
V_58 = F_23 ( & V_11 -> V_70 , 256 , 0 ) ;
if ( V_58 < 0 )
goto V_71;
V_58 = F_24 ( V_11 ) ;
if ( V_58 < 0 )
goto V_72;
F_25 ( V_57 , V_11 ) ;
V_10 ( V_11 , L_3 ,
V_23 >> 10 ) ;
return 0 ;
V_72:
F_26 ( & V_11 -> V_70 ) ;
V_71:
F_27 ( V_11 ) ;
V_60:
F_6 ( V_59 , V_23 ) ;
return V_58 ;
}
static int F_28 ( struct V_56 * V_57 )
{
struct V_10 * V_11 = F_29 ( V_57 ) ;
if ( V_11 ) {
F_30 ( V_11 ) ;
F_6 ( V_59 , V_23 ) ;
F_26 ( & V_11 -> V_70 ) ;
F_27 ( V_11 ) ;
}
return 0 ;
}
static int T_6 F_31 ( void )
{
int V_73 = 0 ;
#ifndef F_32
char * V_74 = NULL ;
if ( F_33 ( L_4 , & V_74 ) )
return - V_75 ;
F_18 ( V_74 ) ;
#endif
if ( ! V_55 )
return - V_76 ;
V_73 = F_34 ( & V_77 ) ;
if ( ! V_73 ) {
V_78 = F_35 ( L_4 , 0 ) ;
if ( V_78 )
V_73 = F_36 ( V_78 ) ;
else
V_73 = - V_24 ;
if ( V_73 ) {
F_37 ( V_78 ) ;
F_38 ( & V_77 ) ;
}
}
return V_73 ;
}
static void T_7 F_39 ( void )
{
F_40 ( V_78 ) ;
F_38 ( & V_77 ) ;
}
