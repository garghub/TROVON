static int F_1 ( struct V_1 * V_2 )
{
unsigned long long V_3 ;
unsigned int V_4 ;
T_1 V_5 ;
V_3 = V_2 -> V_3 * F_2 ( V_2 -> V_6 ) ;
F_3 ( V_3 , V_7 ) ;
V_5 = F_4 ( V_2 -> V_8 + V_9 ) ;
V_5 &= ~ V_10 ;
V_5 |= F_5 ( V_3 ) ;
F_6 ( V_5 , V_2 -> V_8 + V_9 ) ;
for ( V_4 = 0 ; V_4 < V_2 -> V_11 -> V_12 ; V_4 ++ ) {
const struct V_13 * V_14 = & V_2 -> V_11 -> V_15 [ V_4 ] . V_14 ;
T_1 V_5 ;
V_5 = F_4 ( V_2 -> V_8 + V_14 -> V_16 ) ;
V_5 &= ~ ( V_14 -> V_17 << V_14 -> V_18 ) ;
V_5 |= ( V_14 -> V_19 & V_14 -> V_17 ) << V_14 -> V_18 ;
F_6 ( V_5 , V_2 -> V_8 + V_14 -> V_16 ) ;
}
return 0 ;
}
static T_2 F_7 ( int V_20 , void * V_21 )
{
struct V_1 * V_2 = V_21 ;
unsigned long V_22 , V_17 ;
unsigned int V_23 ;
V_22 = F_8 ( V_2 , V_24 ) ;
V_17 = F_8 ( V_2 , V_25 ) ;
F_9 (bit, &status, 32 ) {
const char * error = V_26 [ V_23 ] ? : L_1 ;
const char * V_27 = L_1 , * V_28 ;
const char * V_29 , * V_30 ;
T_3 V_31 = 0 ;
unsigned int V_4 ;
char V_32 [ 7 ] ;
T_4 V_33 , type ;
T_1 V_5 ;
V_5 = F_8 ( V_2 , V_34 ) ;
#ifdef F_10
if ( V_2 -> V_11 -> V_35 > 32 ) {
V_31 = ( ( V_5 >> V_36 ) &
V_37 ) ;
V_31 <<= 32 ;
}
#endif
if ( V_5 & V_38 )
V_29 = L_2 ;
else
V_29 = L_3 ;
if ( V_5 & V_39 )
V_30 = L_4 ;
else
V_30 = L_5 ;
V_33 = V_5 & V_40 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_11 -> V_12 ; V_4 ++ ) {
if ( V_2 -> V_11 -> V_15 [ V_4 ] . V_33 == V_33 ) {
V_27 = V_2 -> V_11 -> V_15 [ V_4 ] . V_41 ;
break;
}
}
type = ( V_5 & V_42 ) >>
V_43 ;
V_28 = V_44 [ type ] ;
switch ( V_5 & V_42 ) {
case V_45 :
V_32 [ 0 ] = ' ' ;
V_32 [ 1 ] = '[' ;
if ( V_5 & V_46 )
V_32 [ 2 ] = 'R' ;
else
V_32 [ 2 ] = '-' ;
if ( V_5 & V_47 )
V_32 [ 3 ] = 'W' ;
else
V_32 [ 3 ] = '-' ;
if ( V_5 & V_48 )
V_32 [ 4 ] = '-' ;
else
V_32 [ 4 ] = 'S' ;
V_32 [ 5 ] = ']' ;
V_32 [ 6 ] = '\0' ;
break;
default:
V_32 [ 0 ] = '\0' ;
break;
}
V_5 = F_8 ( V_2 , V_49 ) ;
V_31 |= V_5 ;
F_11 ( V_2 -> V_50 , L_6 ,
V_27 , V_30 , V_29 , & V_31 , error ,
V_28 , V_32 ) ;
}
F_12 ( V_2 , V_22 , V_24 ) ;
return V_51 ;
}
static int F_13 ( struct V_52 * V_53 )
{
const struct V_54 * V_55 ;
struct V_56 * V_57 ;
struct V_1 * V_2 ;
T_1 V_5 ;
int V_58 ;
V_55 = F_14 ( V_59 , V_53 -> V_50 . V_60 ) ;
if ( ! V_55 )
return - V_61 ;
V_2 = F_15 ( & V_53 -> V_50 , sizeof( * V_2 ) , V_62 ) ;
if ( ! V_2 )
return - V_63 ;
F_16 ( V_53 , V_2 ) ;
V_2 -> V_11 = V_55 -> V_21 ;
V_2 -> V_50 = & V_53 -> V_50 ;
V_2 -> V_3 = 30 ;
V_57 = F_17 ( V_53 , V_64 , 0 ) ;
V_2 -> V_8 = F_18 ( & V_53 -> V_50 , V_57 ) ;
if ( F_19 ( V_2 -> V_8 ) )
return F_20 ( V_2 -> V_8 ) ;
V_2 -> V_6 = F_21 ( & V_53 -> V_50 , L_7 ) ;
if ( F_19 ( V_2 -> V_6 ) ) {
F_22 ( & V_53 -> V_50 , L_8 ,
F_20 ( V_2 -> V_6 ) ) ;
return F_20 ( V_2 -> V_6 ) ;
}
V_58 = F_1 ( V_2 ) ;
if ( V_58 < 0 ) {
F_22 ( & V_53 -> V_50 , L_9 ,
V_58 ) ;
return V_58 ;
}
if ( F_23 ( V_65 ) ) {
V_2 -> V_66 = F_24 ( & V_53 -> V_50 , V_2 -> V_11 -> V_66 , V_2 ) ;
if ( F_19 ( V_2 -> V_66 ) ) {
F_22 ( & V_53 -> V_50 , L_10 ,
F_20 ( V_2 -> V_66 ) ) ;
return F_20 ( V_2 -> V_66 ) ;
}
}
V_2 -> V_20 = F_25 ( V_53 , 0 ) ;
if ( V_2 -> V_20 < 0 ) {
F_22 ( & V_53 -> V_50 , L_11 ) ;
return V_2 -> V_20 ;
}
V_58 = F_26 ( & V_53 -> V_50 , V_2 -> V_20 , F_7 , V_67 ,
F_27 ( & V_53 -> V_50 ) , V_2 ) ;
if ( V_58 < 0 ) {
F_22 ( & V_53 -> V_50 , L_12 , V_2 -> V_20 ,
V_58 ) ;
return V_58 ;
}
V_5 = V_68 | V_69 | V_70 |
V_71 | V_72 |
V_73 | V_74 |
V_75 ;
F_12 ( V_2 , V_5 , V_25 ) ;
return 0 ;
}
static int F_28 ( void )
{
return F_29 ( & V_76 ) ;
}
