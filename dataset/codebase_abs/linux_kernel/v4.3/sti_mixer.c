const char * F_1 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_3 ) {
case V_4 :
return L_1 ;
case V_5 :
return L_2 ;
default:
return L_3 ;
}
}
static inline T_1 F_2 ( struct V_1 * V_2 , T_1 V_6 )
{
return F_3 ( V_2 -> V_7 + V_6 ) ;
}
static inline void F_4 ( struct V_1 * V_2 ,
T_1 V_6 , T_1 V_8 )
{
F_5 ( V_8 , V_2 -> V_7 + V_6 ) ;
}
void F_6 ( struct V_1 * V_2 , bool V_9 )
{
T_1 V_8 = F_2 ( V_2 , V_10 ) ;
V_8 &= ~ V_11 ;
V_8 |= V_9 ;
F_4 ( V_2 , V_10 , V_8 ) ;
}
static void F_7 ( struct V_1 * V_2 ,
T_2 V_12 , T_2 V_13 , T_2 V_14 )
{
T_1 V_8 = ( V_12 << 16 ) | ( V_13 << 8 ) | V_14 ;
F_4 ( V_2 , V_15 , V_8 ) ;
}
static void F_8 ( struct V_1 * V_2 ,
struct V_16 * V_17 )
{
T_1 V_18 , V_19 , V_20 , V_21 ;
V_18 = F_9 ( * V_17 , 0 ) ;
V_20 = F_9 ( * V_17 , V_17 -> V_22 - 1 ) ;
V_19 = F_10 ( * V_17 , 0 ) ;
V_21 = F_10 ( * V_17 , V_17 -> V_23 - 1 ) ;
F_4 ( V_2 , V_24 , V_18 << 16 | V_19 ) ;
F_4 ( V_2 , V_25 , V_20 << 16 | V_21 ) ;
}
int F_11 ( struct V_1 * V_2 , struct V_26 * V_27 )
{
int V_28 , V_29 = V_27 -> V_30 ;
unsigned int V_31 ;
T_1 V_32 , V_8 ;
if ( ( V_29 < 1 ) || ( V_29 > V_33 ) )
return 1 ;
switch ( V_27 -> V_34 ) {
case V_35 :
V_28 = V_36 ;
break;
case V_37 :
V_28 = V_38 ;
break;
case V_39 :
V_28 = V_40 ;
break;
case V_41 :
V_28 = V_42 ;
break;
case V_43 :
V_28 = V_44 ;
break;
case V_45 :
return 0 ;
default:
F_12 ( L_4 , V_27 -> V_34 ) ;
return 1 ;
}
V_8 = F_2 ( V_2 , V_46 ) ;
for ( V_31 = 0 ; V_31 < V_33 ; V_31 ++ ) {
V_32 = V_47 << ( 3 * V_31 ) ;
if ( ( V_8 & V_32 ) == V_28 << ( 3 * V_31 ) )
break;
}
V_32 |= V_47 << ( 3 * ( V_29 - 1 ) ) ;
V_28 = V_28 << ( 3 * ( V_29 - 1 ) ) ;
F_13 ( L_5 , F_1 ( V_2 ) ,
F_14 ( V_27 ) , V_29 ) ;
F_15 ( V_2 -> V_48 , L_6 ,
V_28 , V_32 ) ;
V_8 &= ~ V_32 ;
V_8 |= V_28 ;
F_4 ( V_2 , V_46 , V_8 ) ;
F_15 ( V_2 -> V_48 , L_7 ,
F_2 ( V_2 , V_46 ) ) ;
return 0 ;
}
int F_16 ( struct V_1 * V_2 ,
struct V_16 * V_17 )
{
T_1 V_18 , V_19 , V_20 , V_21 ;
V_18 = F_9 ( * V_17 , 0 ) ;
V_20 = F_9 ( * V_17 , V_17 -> V_22 - 1 ) ;
V_19 = F_10 ( * V_17 , 0 ) ;
V_21 = F_10 ( * V_17 , V_17 -> V_23 - 1 ) ;
F_13 ( L_8 ,
F_1 ( V_2 ) , V_19 , V_18 , V_21 , V_20 ) ;
F_4 ( V_2 , V_49 , V_18 << 16 | V_19 ) ;
F_4 ( V_2 , V_50 , V_20 << 16 | V_21 ) ;
F_7 ( V_2 , 0xFF , 0 , 0 ) ;
F_8 ( V_2 , V_17 ) ;
F_6 ( V_2 , true ) ;
return 0 ;
}
static T_1 F_17 ( struct V_26 * V_27 )
{
switch ( V_27 -> V_34 ) {
case V_51 :
return V_11 ;
case V_35 :
return V_52 ;
case V_37 :
return V_53 ;
case V_39 :
return V_54 ;
case V_41 :
return V_55 ;
case V_43 :
return V_56 ;
case V_45 :
return V_57 ;
default:
return 0 ;
}
}
int F_18 ( struct V_1 * V_2 ,
struct V_26 * V_27 , bool V_58 )
{
T_1 V_32 , V_8 ;
F_13 ( L_9 , V_58 ? L_10 : L_11 ,
F_1 ( V_2 ) , F_14 ( V_27 ) ) ;
V_32 = F_17 ( V_27 ) ;
if ( ! V_32 ) {
F_12 ( L_12 ) ;
return - V_59 ;
}
V_8 = F_2 ( V_2 , V_10 ) ;
V_8 &= ~ V_32 ;
V_8 |= V_58 ? V_32 : 0 ;
F_4 ( V_2 , V_10 , V_8 ) ;
return 0 ;
}
void F_19 ( struct V_1 * V_2 )
{
unsigned int V_31 ;
for ( V_31 = 0 ; V_31 < F_20 ( V_60 ) ; V_31 ++ )
F_4 ( V_2 , V_61 + ( V_31 * 4 ) ,
V_60 [ V_31 ] ) ;
}
struct V_1 * F_21 ( struct V_62 * V_48 , int V_3 ,
void T_3 * V_63 )
{
struct V_1 * V_2 = F_22 ( V_48 , sizeof( * V_2 ) , V_64 ) ;
struct V_65 * V_66 = V_48 -> V_67 ;
F_15 ( V_48 , L_13 , V_68 ) ;
if ( ! V_2 ) {
F_12 ( L_14 ) ;
return NULL ;
}
V_2 -> V_7 = V_63 ;
V_2 -> V_48 = V_48 ;
V_2 -> V_3 = V_3 ;
if ( F_23 ( V_66 , L_15 ) )
F_19 ( V_2 ) ;
F_13 ( L_16 ,
F_1 ( V_2 ) , V_2 -> V_7 ) ;
return V_2 ;
}
