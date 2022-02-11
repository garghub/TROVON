static void F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_4 , T_1 V_5 )
{
T_1 V_6 ;
V_6 = F_2 ( V_2 -> V_7 + V_3 ) ;
V_6 &= ~ V_4 ;
V_6 |= ( V_5 & V_4 ) ;
F_3 ( V_6 , V_2 -> V_7 + V_3 ) ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_8 V_9 ;
int V_10 , V_11 ;
struct V_12 * V_13 = & V_2 -> V_14 -> V_13 ;
char V_15 [ 32 ] ;
const char * V_16 [ 1 ] ;
const char * V_17 [ V_18 ] ;
static struct V_19 V_20 [] = {
{ . V_21 = 0 , . div = 5 } ,
{ . V_21 = 1 , . div = 10 } ,
{ } ,
} ;
for ( V_10 = 0 ; V_10 < V_18 ; V_10 ++ ) {
char V_22 [ 16 ] ;
snprintf ( V_22 , sizeof( V_22 ) , L_1 , V_10 ) ;
V_2 -> V_23 [ V_10 ] = F_5 ( V_13 , V_22 ) ;
if ( F_6 ( V_2 -> V_23 [ V_10 ] ) ) {
V_11 = F_7 ( V_2 -> V_23 [ V_10 ] ) ;
if ( V_11 != - V_24 )
F_8 ( V_13 , L_2 , V_22 ) ;
return V_11 ;
}
V_17 [ V_10 ] =
F_9 ( V_2 -> V_23 [ V_10 ] ) ;
}
snprintf ( V_15 , sizeof( V_15 ) , L_3 , F_10 ( V_13 ) ) ;
V_9 . V_22 = V_15 ;
V_9 . V_25 = & V_26 ;
V_9 . V_27 = 0 ;
V_9 . V_28 = V_17 ;
V_9 . V_29 = V_18 ;
V_2 -> V_30 . V_3 = V_2 -> V_7 + V_31 ;
V_2 -> V_30 . V_32 = V_33 ;
V_2 -> V_30 . V_4 = V_34 ;
V_2 -> V_30 . V_27 = 0 ;
V_2 -> V_30 . V_35 = NULL ;
V_2 -> V_30 . V_36 . V_9 = & V_9 ;
V_2 -> V_37 = F_11 ( V_13 , & V_2 -> V_30 . V_36 ) ;
if ( F_12 ( F_6 ( V_2 -> V_37 ) ) )
return F_7 ( V_2 -> V_37 ) ;
snprintf ( V_15 , sizeof( V_15 ) , L_4 , F_10 ( V_13 ) ) ;
V_9 . V_22 = F_13 ( V_13 , V_15 , V_38 ) ;
V_9 . V_25 = & V_39 ;
V_9 . V_27 = V_40 ;
V_16 [ 0 ] = F_9 ( V_2 -> V_37 ) ;
V_9 . V_28 = V_16 ;
V_9 . V_29 = F_14 ( V_16 ) ;
V_2 -> V_41 . V_3 = V_2 -> V_7 + V_31 ;
V_2 -> V_41 . V_32 = V_42 ;
V_2 -> V_41 . V_43 = V_44 ;
V_2 -> V_41 . V_36 . V_9 = & V_9 ;
V_2 -> V_41 . V_27 = V_45 | V_46 ;
V_2 -> V_47 = F_11 ( V_13 , & V_2 -> V_41 . V_36 ) ;
if ( F_12 ( F_6 ( V_2 -> V_47 ) ) )
return F_7 ( V_2 -> V_47 ) ;
snprintf ( V_15 , sizeof( V_15 ) , L_5 , F_10 ( V_13 ) ) ;
V_9 . V_22 = F_13 ( V_13 , V_15 , V_38 ) ;
V_9 . V_25 = & V_39 ;
V_9 . V_27 = V_48 | V_40 ;
V_16 [ 0 ] = F_9 ( V_2 -> V_47 ) ;
V_9 . V_28 = V_16 ;
V_9 . V_29 = F_14 ( V_16 ) ;
V_2 -> V_49 . V_3 = V_2 -> V_7 + V_31 ;
V_2 -> V_49 . V_32 = V_50 ;
V_2 -> V_49 . V_43 = V_51 ;
V_2 -> V_49 . V_35 = V_20 ;
V_2 -> V_49 . V_36 . V_9 = & V_9 ;
V_2 -> V_49 . V_27 = V_46 ;
V_2 -> V_52 = F_11 ( V_13 , & V_2 -> V_49 . V_36 ) ;
if ( F_12 ( F_6 ( V_2 -> V_52 ) ) )
return F_7 ( V_2 -> V_52 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 )
{
int V_11 ;
unsigned long V_53 ;
switch ( V_2 -> V_54 ) {
case V_55 :
case V_56 :
case V_57 :
case V_58 :
V_53 = 25 * 1000 * 1000 ;
F_1 ( V_2 , V_31 , V_59 ,
V_59 ) ;
F_1 ( V_2 , V_31 ,
V_60 , 0 ) ;
F_1 ( V_2 , V_31 , V_61 ,
V_62 ) ;
break;
case V_63 :
V_53 = F_16 ( V_2 -> V_37 ) ;
F_1 ( V_2 , V_31 , V_59 ,
0 ) ;
F_1 ( V_2 , V_31 ,
V_60 ,
V_60 ) ;
F_1 ( V_2 , V_31 , V_61 ,
0 ) ;
break;
default:
F_8 ( & V_2 -> V_14 -> V_13 , L_6 ,
F_17 ( V_2 -> V_54 ) ) ;
return - V_64 ;
}
V_11 = F_18 ( V_2 -> V_52 ) ;
if ( V_11 ) {
F_8 ( & V_2 -> V_14 -> V_13 , L_7 ) ;
return V_11 ;
}
V_11 = F_19 ( V_2 -> V_52 , V_53 ) ;
if ( V_11 ) {
F_20 ( V_2 -> V_52 ) ;
F_8 ( & V_2 -> V_14 -> V_13 , L_8 ) ;
return V_11 ;
}
F_1 ( V_2 , V_31 , V_65 ,
V_65 ) ;
return 0 ;
}
static int F_21 ( struct V_66 * V_14 )
{
struct V_67 * V_68 ;
struct V_69 V_70 ;
struct V_71 * V_72 ;
struct V_1 * V_2 ;
int V_11 ;
V_11 = F_22 ( V_14 , & V_70 ) ;
if ( V_11 )
return V_11 ;
V_68 = F_23 ( V_14 , & V_70 . V_73 ) ;
if ( F_6 ( V_68 ) )
return F_7 ( V_68 ) ;
V_2 = F_24 ( & V_14 -> V_13 , sizeof( * V_2 ) , V_38 ) ;
if ( ! V_2 ) {
V_11 = - V_74 ;
goto V_75;
}
V_72 = F_25 ( V_14 , V_76 , 1 ) ;
V_2 -> V_7 = F_26 ( & V_14 -> V_13 , V_72 ) ;
if ( F_6 ( V_2 -> V_7 ) ) {
V_11 = F_7 ( V_2 -> V_7 ) ;
goto V_75;
}
V_2 -> V_14 = V_14 ;
V_2 -> V_54 = F_27 ( V_14 -> V_13 . V_77 ) ;
if ( V_2 -> V_54 < 0 ) {
F_8 ( & V_14 -> V_13 , L_9 ) ;
V_11 = - V_64 ;
goto V_75;
}
V_11 = F_4 ( V_2 ) ;
if ( V_11 )
goto V_75;
V_11 = F_15 ( V_2 ) ;
if ( V_11 )
goto V_75;
V_68 -> V_78 = V_2 ;
V_11 = F_28 ( & V_14 -> V_13 , V_68 , & V_70 ) ;
if ( V_11 )
goto V_79;
return 0 ;
V_79:
F_20 ( V_2 -> V_52 ) ;
V_75:
F_29 ( V_14 , V_68 ) ;
return V_11 ;
}
static int F_30 ( struct V_66 * V_14 )
{
struct V_1 * V_2 = F_31 ( & V_14 -> V_13 ) ;
F_20 ( V_2 -> V_52 ) ;
return F_32 ( V_14 ) ;
}
