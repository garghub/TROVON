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
unsigned int V_12 )
{
F_4 ( V_2 , V_13 , V_12 ) ;
}
static void F_8 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
T_1 V_16 , V_17 , V_18 , V_19 ;
V_16 = F_9 ( * V_15 , 0 ) ;
V_18 = F_9 ( * V_15 , V_15 -> V_20 - 1 ) ;
V_17 = F_10 ( * V_15 , 0 ) ;
V_19 = F_10 ( * V_15 , V_15 -> V_21 - 1 ) ;
F_4 ( V_2 , V_22 , V_16 << 16 | V_17 ) ;
F_4 ( V_2 , V_23 , V_18 << 16 | V_19 ) ;
}
int F_11 ( struct V_1 * V_2 , struct V_24 * V_25 )
{
int V_26 , V_27 = V_25 -> V_28 ;
unsigned int V_29 ;
T_1 V_30 , V_8 ;
if ( ( V_27 < 1 ) || ( V_27 > V_31 ) )
return 1 ;
switch ( V_25 -> V_32 ) {
case V_33 :
V_26 = V_34 ;
break;
case V_35 :
V_26 = V_36 ;
break;
case V_37 :
V_26 = V_38 ;
break;
case V_39 :
V_26 = V_40 ;
break;
case V_41 :
V_26 = V_42 ;
break;
case V_43 :
return 0 ;
default:
F_12 ( L_4 , V_25 -> V_32 ) ;
return 1 ;
}
V_8 = F_2 ( V_2 , V_44 ) ;
for ( V_29 = 0 ; V_29 < V_31 ; V_29 ++ ) {
V_30 = V_45 << ( 3 * V_29 ) ;
if ( ( V_8 & V_30 ) == V_26 << ( 3 * V_29 ) )
break;
}
V_30 |= V_45 << ( 3 * ( V_27 - 1 ) ) ;
V_26 = V_26 << ( 3 * ( V_27 - 1 ) ) ;
F_13 ( L_5 , F_1 ( V_2 ) ,
F_14 ( V_25 ) , V_27 ) ;
F_15 ( V_2 -> V_46 , L_6 ,
V_26 , V_30 ) ;
V_8 &= ~ V_30 ;
V_8 |= V_26 ;
F_4 ( V_2 , V_44 , V_8 ) ;
F_15 ( V_2 -> V_46 , L_7 ,
F_2 ( V_2 , V_44 ) ) ;
return 0 ;
}
int F_16 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
T_1 V_16 , V_17 , V_18 , V_19 ;
V_16 = F_9 ( * V_15 , 0 ) ;
V_18 = F_9 ( * V_15 , V_15 -> V_20 - 1 ) ;
V_17 = F_10 ( * V_15 , 0 ) ;
V_19 = F_10 ( * V_15 , V_15 -> V_21 - 1 ) ;
F_13 ( L_8 ,
F_1 ( V_2 ) , V_17 , V_16 , V_19 , V_18 ) ;
F_4 ( V_2 , V_47 , V_16 << 16 | V_17 ) ;
F_4 ( V_2 , V_48 , V_18 << 16 | V_19 ) ;
F_7 ( V_2 , V_49 ) ;
F_8 ( V_2 , V_15 ) ;
F_6 ( V_2 , true ) ;
return 0 ;
}
static T_1 F_17 ( struct V_24 * V_25 )
{
switch ( V_25 -> V_32 ) {
case V_50 :
return V_11 ;
case V_33 :
return V_51 ;
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
default:
return 0 ;
}
}
int F_18 ( struct V_1 * V_2 ,
struct V_24 * V_25 , bool V_57 )
{
T_1 V_30 , V_8 ;
F_13 ( L_9 , V_57 ? L_10 : L_11 ,
F_1 ( V_2 ) , F_14 ( V_25 ) ) ;
V_30 = F_17 ( V_25 ) ;
if ( ! V_30 ) {
F_12 ( L_12 ) ;
return - V_58 ;
}
V_8 = F_2 ( V_2 , V_10 ) ;
V_8 &= ~ V_30 ;
V_8 |= V_57 ? V_30 : 0 ;
F_4 ( V_2 , V_10 , V_8 ) ;
return 0 ;
}
void F_19 ( struct V_1 * V_2 )
{
unsigned int V_29 ;
for ( V_29 = 0 ; V_29 < F_20 ( V_59 ) ; V_29 ++ )
F_4 ( V_2 , V_60 + ( V_29 * 4 ) ,
V_59 [ V_29 ] ) ;
}
struct V_1 * F_21 ( struct V_61 * V_46 , int V_3 ,
void T_2 * V_62 )
{
struct V_1 * V_2 = F_22 ( V_46 , sizeof( * V_2 ) , V_63 ) ;
struct V_64 * V_65 = V_46 -> V_66 ;
F_15 ( V_46 , L_13 , V_67 ) ;
if ( ! V_2 ) {
F_12 ( L_14 ) ;
return NULL ;
}
V_2 -> V_7 = V_62 ;
V_2 -> V_46 = V_46 ;
V_2 -> V_3 = V_3 ;
if ( F_23 ( V_65 , L_15 ) )
F_19 ( V_2 ) ;
F_13 ( L_16 ,
F_1 ( V_2 ) , V_2 -> V_7 ) ;
return V_2 ;
}
