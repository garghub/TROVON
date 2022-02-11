static T_1 F_1 ( struct V_1 * V_2 , int V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static void F_3 ( struct V_1 * V_2 , int V_3 , T_1 V_5 )
{
F_4 ( V_2 -> V_4 + V_3 , V_5 ) ;
}
static void F_5 ( struct V_6 * V_7 )
{
struct V_1 * V_2 ;
unsigned long V_8 ;
T_1 V_9 , V_10 ;
V_2 = V_7 -> V_11 ;
V_10 = ( 1 << ( 31 - F_6 ( V_7 ) ) ) ;
F_7 ( & V_2 -> V_12 , V_8 ) ;
V_9 = F_1 ( V_2 , V_13 ) ;
F_3 ( V_2 , V_13 , V_9 | V_10 ) ;
V_9 = F_1 ( V_2 , V_13 ) ;
F_8 ( & V_2 -> V_12 , V_8 ) ;
}
static void F_9 ( struct V_6 * V_7 )
{
struct V_1 * V_2 ;
unsigned long V_8 ;
T_1 V_9 , V_14 ;
V_2 = V_7 -> V_11 ;
V_14 = ~ ( 1 << ( 31 - F_6 ( V_7 ) ) ) ;
F_7 ( & V_2 -> V_12 , V_8 ) ;
V_9 = F_1 ( V_2 , V_13 ) ;
F_3 ( V_2 , V_13 , V_9 & V_14 ) ;
V_9 = F_1 ( V_2 , V_13 ) ;
F_8 ( & V_2 -> V_12 , V_8 ) ;
}
static void F_10 ( struct V_6 * V_7 )
{
struct V_1 * V_2 ;
unsigned long V_8 ;
T_1 V_10 ;
V_2 = V_7 -> V_11 ;
V_10 = ( 1 << ( 31 - F_6 ( V_7 ) ) ) ;
F_7 ( & V_2 -> V_12 , V_8 ) ;
F_3 ( V_2 , V_15 , V_10 ) ;
F_1 ( V_2 , V_15 ) ;
F_8 ( & V_2 -> V_12 , V_8 ) ;
}
static void F_11 ( struct V_6 * V_7 )
{
struct V_1 * V_2 ;
unsigned long V_8 ;
T_1 V_10 ;
T_1 V_9 , V_16 ;
V_2 = V_7 -> V_11 ;
V_10 = ( 1 << ( 31 - F_6 ( V_7 ) ) ) ;
F_7 ( & V_2 -> V_12 , V_8 ) ;
V_9 = F_1 ( V_2 , V_13 ) ;
F_3 ( V_2 , V_13 , V_9 & ~ V_10 ) ;
V_9 = F_1 ( V_2 , V_13 ) ;
F_3 ( V_2 , V_15 , V_10 ) ;
V_16 = F_1 ( V_2 , V_15 ) ;
F_8 ( & V_2 -> V_12 , V_8 ) ;
}
static int F_12 ( struct V_6 * V_7 , unsigned int V_17 )
{
struct V_1 * V_2 ;
unsigned long V_8 ;
int V_18 , V_19 , V_14 , V_20 ;
V_2 = V_7 -> V_11 ;
switch ( V_17 ) {
case V_21 :
F_9 ( V_7 ) ;
return 0 ;
case V_22 :
V_18 = 0 ;
break;
case V_23 :
V_18 = 1 ;
break;
default:
return - V_24 ;
}
V_20 = ( 1 << ( 31 - F_6 ( V_7 ) ) ) ;
V_14 = ~ V_20 ;
F_7 ( & V_2 -> V_12 , V_8 ) ;
V_19 = F_1 ( V_2 , V_25 ) ;
V_19 = ( V_19 & V_14 ) | ( V_18 ? V_20 : 0 ) ;
F_3 ( V_2 , V_25 , V_19 ) ;
V_19 = F_1 ( V_2 , V_25 ) ;
F_8 ( & V_2 -> V_12 , V_8 ) ;
F_13 ( V_7 , V_17 ) ;
return 0 ;
}
static int F_14 ( struct V_26 * V_27 , unsigned int V_28 ,
T_2 V_29 )
{
struct V_1 * V_2 ;
V_2 = V_27 -> V_30 ;
F_15 ( V_28 , V_2 ) ;
F_16 ( V_28 , & V_31 , V_32 ) ;
F_17 ( V_28 , V_21 ) ;
return 0 ;
}
T_3 F_18 ( int V_33 , void * V_34 )
{
struct V_1 * V_2 ;
T_1 V_16 , V_35 , V_36 ;
V_2 = (struct V_1 * ) V_34 ;
V_16 = F_1 ( V_2 , V_15 ) ;
if ( ! V_16 )
return V_37 ;
do {
V_35 = 32 - F_19 ( V_16 ) ;
V_36 = F_20 ( V_2 -> V_27 , V_35 ) ;
F_21 ( V_36 ) ;
} while ( ( V_16 = F_1 ( V_2 , V_15 ) ) );
return V_38 ;
}
struct V_1 * F_22 ( struct V_39 * V_40 )
{
struct V_1 * V_2 ;
struct V_41 V_42 ;
if ( F_23 ( V_40 , 0 , & V_42 ) ) {
F_24 ( V_43 L_1 ) ;
return NULL ;
}
V_2 = F_25 ( sizeof( struct V_1 ) , V_44 ) ;
if ( ! V_2 ) {
F_24 ( V_43 L_2 ) ;
return NULL ;
}
V_2 -> V_4 = F_26 ( V_42 . V_45 + 0x10000 , 0x1000 ) ;
if ( ! V_2 -> V_4 ) {
F_24 ( V_43 L_3 ) ;
goto V_46;
}
V_2 -> V_27 = F_27 ( V_40 , V_47 , & V_48 , V_2 ) ;
if ( ! V_2 -> V_27 ) {
F_24 ( V_43 L_4 ) ;
goto V_49;
}
V_2 -> V_50 = V_51 ++ ;
F_28 ( & V_2 -> V_12 ) ;
F_3 ( V_2 , V_52 , 0 ) ;
F_3 ( V_2 , V_13 , 0 ) ;
F_3 ( V_2 , V_15 , 0xFFFFFFFF ) ;
return V_2 ;
V_49:
F_29 ( V_2 -> V_4 ) ;
V_46:
F_30 ( V_2 ) ;
return NULL ;
}
void T_4 F_31 ( void )
{
struct V_39 * V_40 ;
struct V_1 * V_2 ;
int V_28 ;
int V_53 ;
F_32 (dn, NULL, L_5 ) {
V_2 = F_22 ( V_40 ) ;
if ( ! V_2 ) {
F_24 ( V_54 L_6 ) ;
continue;
}
V_28 = F_33 ( V_40 , 0 ) ;
if ( V_28 <= 0 ) {
F_24 ( L_7 ) ;
continue;
}
V_53 = F_34 ( V_28 , F_18 , V_55 ,
L_8 , V_2 ) ;
if ( V_53 ) {
F_24 ( L_9 , V_53 ) ;
continue;
}
F_24 ( L_10 , V_2 -> V_50 ,
V_47 , V_2 -> V_4 ) ;
}
}
