static T_1 F_1 ( int V_1 , int V_2 )
{
T_1 V_3 ;
V_3 = V_1 * V_2 ;
V_3 = ( V_3 + 31 ) & ~ 31 ;
V_3 >>= 3 ;
return ( V_3 ) ;
}
static int F_2 ( struct V_4 * V_5 ,
struct V_6 * V_7 )
{
T_1 V_8 ;
if ( V_5 -> V_9 & V_10 ) {
V_5 -> V_9 |= V_11 ;
V_5 -> V_12 = V_7 -> V_5 . V_12 ;
V_5 -> V_13 = V_7 -> V_5 . V_13 ;
}
if ( ! V_5 -> V_14 )
V_5 -> V_14 = 1 ;
if ( ! V_5 -> V_15 )
V_5 -> V_15 = 1 ;
if ( V_5 -> V_14 > V_5 -> V_1 )
V_5 -> V_1 = V_5 -> V_14 ;
if ( V_5 -> V_15 > V_5 -> V_16 )
V_5 -> V_16 = V_5 -> V_15 ;
if ( V_5 -> V_17 <= 1 )
V_5 -> V_17 = 1 ;
else if ( V_5 -> V_17 <= 8 )
V_5 -> V_17 = 8 ;
else if ( V_5 -> V_17 <= 16 )
V_5 -> V_17 = 16 ;
else if ( V_5 -> V_17 <= 24 )
V_5 -> V_17 = 24 ;
else if ( V_5 -> V_17 <= 32 )
V_5 -> V_17 = 32 ;
else
return - V_18 ;
if ( V_5 -> V_1 < V_5 -> V_12 + V_5 -> V_14 )
V_5 -> V_1 = V_5 -> V_12 + V_5 -> V_14 ;
if ( V_5 -> V_16 < V_5 -> V_13 + V_5 -> V_15 )
V_5 -> V_16 = V_5 -> V_13 + V_5 -> V_15 ;
V_8 =
F_1 ( V_5 -> V_1 , V_5 -> V_17 ) ;
if ( V_8 * V_5 -> V_16 > V_19 )
return - V_20 ;
switch ( V_5 -> V_17 ) {
case 1 :
case 8 :
V_5 -> V_21 . V_22 = 0 ;
V_5 -> V_21 . V_3 = 8 ;
V_5 -> V_23 . V_22 = 0 ;
V_5 -> V_23 . V_3 = 8 ;
V_5 -> V_24 . V_22 = 0 ;
V_5 -> V_24 . V_3 = 8 ;
V_5 -> V_25 . V_22 = 0 ;
V_5 -> V_25 . V_3 = 0 ;
break;
case 16 :
if ( V_5 -> V_25 . V_3 ) {
V_5 -> V_21 . V_22 = 0 ;
V_5 -> V_21 . V_3 = 5 ;
V_5 -> V_23 . V_22 = 5 ;
V_5 -> V_23 . V_3 = 5 ;
V_5 -> V_24 . V_22 = 10 ;
V_5 -> V_24 . V_3 = 5 ;
V_5 -> V_25 . V_22 = 15 ;
V_5 -> V_25 . V_3 = 1 ;
} else {
V_5 -> V_21 . V_22 = 0 ;
V_5 -> V_21 . V_3 = 5 ;
V_5 -> V_23 . V_22 = 5 ;
V_5 -> V_23 . V_3 = 6 ;
V_5 -> V_24 . V_22 = 11 ;
V_5 -> V_24 . V_3 = 5 ;
V_5 -> V_25 . V_22 = 0 ;
V_5 -> V_25 . V_3 = 0 ;
}
break;
case 24 :
V_5 -> V_21 . V_22 = 0 ;
V_5 -> V_21 . V_3 = 8 ;
V_5 -> V_23 . V_22 = 8 ;
V_5 -> V_23 . V_3 = 8 ;
V_5 -> V_24 . V_22 = 16 ;
V_5 -> V_24 . V_3 = 8 ;
V_5 -> V_25 . V_22 = 0 ;
V_5 -> V_25 . V_3 = 0 ;
break;
case 32 :
V_5 -> V_21 . V_22 = 0 ;
V_5 -> V_21 . V_3 = 8 ;
V_5 -> V_23 . V_22 = 8 ;
V_5 -> V_23 . V_3 = 8 ;
V_5 -> V_24 . V_22 = 16 ;
V_5 -> V_24 . V_3 = 8 ;
V_5 -> V_25 . V_22 = 24 ;
V_5 -> V_25 . V_3 = 8 ;
break;
}
V_5 -> V_21 . V_26 = 0 ;
V_5 -> V_23 . V_26 = 0 ;
V_5 -> V_24 . V_26 = 0 ;
V_5 -> V_25 . V_26 = 0 ;
return 0 ;
}
static int F_3 ( struct V_6 * V_7 )
{
V_7 -> V_27 . V_8 = F_1 ( V_7 -> V_5 . V_1 ,
V_7 -> V_5 . V_17 ) ;
return 0 ;
}
static int F_4 ( T_2 V_28 , T_2 V_21 , T_2 V_23 , T_2 V_24 ,
T_2 V_25 , struct V_6 * V_7 )
{
if ( V_28 >= 256 )
return 1 ;
if ( V_7 -> V_5 . V_29 ) {
V_21 = V_23 = V_24 =
( V_21 * 77 + V_23 * 151 + V_24 * 28 ) >> 8 ;
}
#define F_5 ( T_3 , T_4 ) ((((val)<<(width))+0x7FFF-(val))>>16)
switch ( V_7 -> V_27 . V_30 ) {
case V_31 :
case V_32 :
V_21 = F_5 ( V_21 , V_7 -> V_5 . V_21 . V_3 ) ;
V_23 = F_5 ( V_23 , V_7 -> V_5 . V_23 . V_3 ) ;
V_24 = F_5 ( V_24 , V_7 -> V_5 . V_24 . V_3 ) ;
V_25 = F_5 ( V_25 , V_7 -> V_5 . V_25 . V_3 ) ;
break;
case V_33 :
V_21 = F_5 ( V_21 , 8 ) ;
V_23 = F_5 ( V_23 , 8 ) ;
V_24 = F_5 ( V_24 , 8 ) ;
V_25 = F_5 ( V_25 , 8 ) ;
break;
}
#undef F_5
if ( V_7 -> V_27 . V_30 == V_31 ) {
T_5 V_34 ;
if ( V_28 >= 16 )
return 1 ;
V_34 = ( V_21 << V_7 -> V_5 . V_21 . V_22 ) |
( V_23 << V_7 -> V_5 . V_23 . V_22 ) |
( V_24 << V_7 -> V_5 . V_24 . V_22 ) |
( V_25 << V_7 -> V_5 . V_25 . V_22 ) ;
switch ( V_7 -> V_5 . V_17 ) {
case 8 :
break;
case 16 :
( ( T_5 * ) ( V_7 -> V_35 ) ) [ V_28 ] = V_34 ;
break;
case 24 :
case 32 :
( ( T_5 * ) ( V_7 -> V_35 ) ) [ V_28 ] = V_34 ;
break;
}
return 0 ;
}
return 0 ;
}
static int F_6 ( struct V_4 * V_5 ,
struct V_6 * V_7 )
{
if ( V_5 -> V_9 & V_11 ) {
if ( V_5 -> V_13 >= V_7 -> V_5 . V_16 ||
V_5 -> V_12 )
return - V_18 ;
} else {
if ( V_5 -> V_12 + V_7 -> V_5 . V_14 > V_7 -> V_5 . V_1 ||
V_5 -> V_13 + V_7 -> V_5 . V_15 > V_7 -> V_5 . V_16 )
return - V_18 ;
}
V_7 -> V_5 . V_12 = V_5 -> V_12 ;
V_7 -> V_5 . V_13 = V_5 -> V_13 ;
if ( V_5 -> V_9 & V_11 )
V_7 -> V_5 . V_9 |= V_11 ;
else
V_7 -> V_5 . V_9 &= ~ V_11 ;
return 0 ;
}
static int F_7 ( struct V_6 * V_7 ,
struct V_36 * V_37 )
{
return F_8 ( V_37 , ( void * ) V_7 -> V_27 . V_38 , V_37 -> V_39 ) ;
}
static int T_6 F_9 ( char * V_40 )
{
char * V_41 ;
V_42 = 0 ;
if ( ! V_40 )
return 1 ;
V_42 = 1 ;
if ( ! * V_40 )
return 1 ;
while ( ( V_41 = F_10 ( & V_40 , L_1 ) ) != NULL ) {
if ( ! * V_41 )
continue;
if ( ! strcmp ( V_41 , L_2 ) )
V_42 = 0 ;
else
V_43 = V_41 ;
}
return 1 ;
}
static int F_11 ( struct V_44 * V_45 )
{
struct V_6 * V_7 ;
unsigned int V_46 = F_12 ( V_19 ) ;
int V_47 = - V_20 ;
if ( ! ( V_48 = F_13 ( V_46 ) ) )
return V_47 ;
V_7 = F_14 ( sizeof( T_5 ) * 256 , & V_45 -> V_45 ) ;
if ( ! V_7 )
goto V_49;
V_7 -> V_50 = ( char V_51 * ) V_48 ;
V_7 -> V_52 = & V_53 ;
if ( ! F_15 ( & V_7 -> V_5 , V_7 , V_43 ,
NULL , 0 , & V_54 , 8 ) ) {
F_16 ( V_7 , L_3 ) ;
V_47 = - V_18 ;
goto V_55;
}
V_56 . V_38 = ( unsigned long ) V_48 ;
V_56 . V_57 = V_19 ;
V_7 -> V_27 = V_56 ;
V_7 -> V_35 = V_7 -> V_58 ;
V_7 -> V_58 = NULL ;
V_7 -> V_59 = V_60 ;
V_47 = F_17 ( & V_7 -> V_61 , 256 , 0 ) ;
if ( V_47 < 0 )
goto V_55;
V_47 = F_18 ( V_7 ) ;
if ( V_47 < 0 )
goto V_62;
F_19 ( V_45 , V_7 ) ;
V_6 ( V_7 , L_4 ,
V_19 >> 10 ) ;
return 0 ;
V_62:
F_20 ( & V_7 -> V_61 ) ;
V_55:
F_21 ( V_7 ) ;
V_49:
F_22 ( V_48 ) ;
return V_47 ;
}
static int F_23 ( struct V_44 * V_45 )
{
struct V_6 * V_7 = F_24 ( V_45 ) ;
if ( V_7 ) {
F_25 ( V_7 ) ;
F_22 ( V_48 ) ;
F_20 ( & V_7 -> V_61 ) ;
F_21 ( V_7 ) ;
}
return 0 ;
}
static int T_6 F_26 ( void )
{
int V_63 = 0 ;
#ifndef F_27
char * V_64 = NULL ;
if ( F_28 ( L_5 , & V_64 ) )
return - V_65 ;
F_9 ( V_64 ) ;
#endif
if ( ! V_42 )
return - V_66 ;
V_63 = F_29 ( & V_67 ) ;
if ( ! V_63 ) {
V_68 = F_30 ( L_5 , 0 ) ;
if ( V_68 )
V_63 = F_31 ( V_68 ) ;
else
V_63 = - V_20 ;
if ( V_63 ) {
F_32 ( V_68 ) ;
F_33 ( & V_67 ) ;
}
}
return V_63 ;
}
static void T_7 F_34 ( void )
{
F_35 ( V_68 ) ;
F_33 ( & V_67 ) ;
}
