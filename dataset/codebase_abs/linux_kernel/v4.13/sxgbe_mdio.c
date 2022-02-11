static int F_1 ( void T_1 * V_1 , unsigned int V_2 )
{
unsigned long V_3 = V_4 + 3 * V_5 ;
while ( ! F_2 ( V_4 , V_3 ) ) {
if ( ! ( F_3 ( V_1 + V_2 ) & V_6 ) )
return 0 ;
F_4 () ;
}
return - V_7 ;
}
static void F_5 ( struct V_8 * V_9 , T_2 V_10 ,
T_3 V_11 )
{
T_2 V_12 = V_11 ;
V_12 |= ( V_10 << 16 ) | V_13 |
( ( V_9 -> V_14 & 0x7 ) << 19 ) | V_6 ;
F_6 ( V_12 , V_9 -> V_1 + V_9 -> V_15 -> V_16 . V_17 ) ;
}
static void F_7 ( struct V_8 * V_9 , T_2 V_10 , int V_18 ,
int V_19 , T_3 V_11 )
{
T_2 V_12 ;
V_12 = ( ( V_19 >> 16 ) & 0x1f ) << 21 ;
V_12 |= ( V_18 << 16 ) | ( V_19 & 0xffff ) ;
F_6 ( V_12 , V_9 -> V_1 + V_9 -> V_15 -> V_16 . V_20 ) ;
F_5 ( V_9 , V_10 , V_11 ) ;
}
static void F_8 ( struct V_8 * V_9 , T_2 V_10 , int V_18 ,
int V_19 , T_3 V_11 )
{
T_2 V_12 ;
F_6 ( 1 << V_18 , V_9 -> V_1 + V_21 ) ;
V_12 = ( V_18 << 16 ) | ( V_19 & 0x1f ) ;
F_6 ( V_12 , V_9 -> V_1 + V_9 -> V_15 -> V_16 . V_20 ) ;
F_5 ( V_9 , V_10 , V_11 ) ;
}
static int F_9 ( struct V_8 * V_9 , T_2 V_10 , int V_18 ,
int V_19 , T_3 V_11 )
{
const struct V_22 * V_16 = & V_9 -> V_15 -> V_16 ;
int V_23 ;
V_23 = F_1 ( V_9 -> V_1 , V_16 -> V_17 ) ;
if ( V_23 < 0 )
return V_23 ;
if ( V_19 & V_24 ) {
F_7 ( V_9 , V_10 , V_18 , V_19 , V_11 ) ;
} else {
if ( V_18 >= 4 )
return - V_25 ;
F_8 ( V_9 , V_10 , V_18 , V_19 , V_11 ) ;
}
return F_1 ( V_9 -> V_1 , V_16 -> V_17 ) ;
}
static int F_10 ( struct V_26 * V_27 , int V_18 , int V_19 )
{
struct V_28 * V_29 = V_27 -> V_30 ;
struct V_8 * V_30 = F_11 ( V_29 ) ;
int V_23 ;
V_23 = F_9 ( V_30 , V_31 , V_18 , V_19 , 0 ) ;
if ( V_23 < 0 )
return V_23 ;
return F_3 ( V_30 -> V_1 + V_30 -> V_15 -> V_16 . V_17 ) & 0xffff ;
}
static int F_12 ( struct V_26 * V_27 , int V_18 , int V_19 ,
T_3 V_11 )
{
struct V_28 * V_29 = V_27 -> V_30 ;
struct V_8 * V_30 = F_11 ( V_29 ) ;
return F_9 ( V_30 , V_32 , V_18 , V_19 ,
V_11 ) ;
}
int F_13 ( struct V_28 * V_29 )
{
struct V_26 * V_33 ;
struct V_8 * V_30 = F_11 ( V_29 ) ;
struct V_34 * V_35 = V_30 -> V_36 -> V_37 ;
int V_38 , V_39 ;
int * V_40 ;
bool V_41 = false ;
bool V_42 ;
V_33 = F_14 () ;
if ( ! V_33 ) {
F_15 ( V_29 , L_1 , V_43 ) ;
return - V_44 ;
}
if ( V_35 -> V_45 )
V_40 = V_35 -> V_45 ;
else
V_40 = V_30 -> V_46 ;
V_33 -> V_47 = L_2 ;
V_33 -> V_48 = & F_10 ;
V_33 -> V_49 = & F_12 ;
snprintf ( V_33 -> V_50 , V_51 , L_3 ,
V_33 -> V_47 , V_30 -> V_36 -> V_52 ) ;
V_33 -> V_30 = V_29 ;
V_33 -> V_53 = V_35 -> V_53 ;
V_33 -> V_54 = V_30 -> V_55 ;
V_38 = F_16 ( V_33 ) ;
if ( V_38 != 0 ) {
F_15 ( V_29 , L_4 ) ;
goto V_56;
}
for ( V_39 = 0 ; V_39 < V_57 ; V_39 ++ ) {
struct V_58 * V_59 = F_17 ( V_33 , V_39 ) ;
if ( V_59 ) {
char V_60 [ 4 ] ;
char * V_61 ;
if ( ( V_35 -> V_45 == NULL ) &&
( V_35 -> V_62 > 0 ) ) {
V_40 [ V_39 ] = V_35 -> V_62 ;
V_59 -> V_63 = V_35 -> V_62 ;
}
if ( V_30 -> V_36 -> V_39 == - 1 )
V_30 -> V_36 -> V_39 = V_39 ;
V_42 = ( V_30 -> V_36 -> V_39 == V_39 ) ;
switch ( V_59 -> V_63 ) {
case V_64 :
V_61 = L_5 ;
break;
case V_65 :
V_61 = L_6 ;
break;
default:
sprintf ( V_60 , L_7 , V_59 -> V_63 ) ;
V_61 = V_60 ;
break;
}
F_18 ( V_29 , L_8 ,
V_59 -> V_66 , V_39 , V_61 ,
F_19 ( V_59 ) , V_42 ? L_9 : L_10 ) ;
V_41 = true ;
}
}
if ( ! V_41 ) {
F_15 ( V_29 , L_11 ) ;
goto V_67;
}
V_30 -> V_16 = V_33 ;
return 0 ;
V_67:
V_38 = - V_25 ;
F_20 ( V_33 ) ;
V_56:
F_21 ( V_33 ) ;
return V_38 ;
}
int F_22 ( struct V_28 * V_29 )
{
struct V_8 * V_30 = F_11 ( V_29 ) ;
if ( ! V_30 -> V_16 )
return 0 ;
F_20 ( V_30 -> V_16 ) ;
V_30 -> V_16 -> V_30 = NULL ;
F_21 ( V_30 -> V_16 ) ;
V_30 -> V_16 = NULL ;
return 0 ;
}
