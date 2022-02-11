static void F_1 ( struct V_1 * V_2 ,
int V_3 , int V_4 , int V_5 , int V_6 )
{
F_2 ( V_7 , V_2 ,
L_1 ,
V_8 , V_3 , V_4 , V_5 , V_6 ) ;
switch ( V_2 -> V_9 -> V_10 . V_11 ) {
case 0 :
F_3 ( V_2 , 0x0020 , V_3 ) ;
F_3 ( V_2 , 0x0021 , V_4 ) ;
break;
case 180 :
F_3 ( V_2 , 0x0020 , V_12 - 1 - V_3 ) ;
F_3 ( V_2 , 0x0021 , V_13 - 1 - V_4 ) ;
break;
case 270 :
F_3 ( V_2 , 0x0020 , V_12 - 1 - V_4 ) ;
F_3 ( V_2 , 0x0021 , V_3 ) ;
break;
case 90 :
F_3 ( V_2 , 0x0020 , V_4 ) ;
F_3 ( V_2 , 0x0021 , V_13 - 1 - V_3 ) ;
break;
}
F_3 ( V_2 , 0x0022 ) ;
}
static void F_4 ( struct V_1 * V_2 ,
int V_3 , int V_4 , int V_5 , int V_6 )
{
F_2 ( V_7 , V_2 ,
L_1 ,
V_8 , V_3 , V_4 , V_5 , V_6 ) ;
switch ( V_2 -> V_9 -> V_10 . V_11 ) {
case 0 :
F_3 ( V_2 , 0x4e , V_3 ) ;
F_3 ( V_2 , 0x4f , V_4 ) ;
break;
case 180 :
F_3 ( V_2 , 0x4e , V_2 -> V_9 -> V_10 . V_14 - 1 - V_3 ) ;
F_3 ( V_2 , 0x4f , V_2 -> V_9 -> V_10 . V_15 - 1 - V_4 ) ;
break;
case 270 :
F_3 ( V_2 , 0x4e , V_2 -> V_9 -> V_10 . V_15 - 1 - V_4 ) ;
F_3 ( V_2 , 0x4f , V_3 ) ;
break;
case 90 :
F_3 ( V_2 , 0x4e , V_4 ) ;
F_3 ( V_2 , 0x4f , V_2 -> V_9 -> V_10 . V_14 - 1 - V_3 ) ;
break;
}
F_3 ( V_2 , 0x22 , 0 ) ;
}
static void F_5 ( struct V_1 * V_2 ,
int V_3 , int V_4 , int V_5 , int V_6 )
{
F_2 ( V_7 , V_2 ,
L_1 , V_8 ,
V_3 , V_4 , V_5 , V_6 ) ;
F_3 ( V_2 , 0x15 , V_3 , V_5 ) ;
F_3 ( V_2 , 0x75 , V_4 , V_6 ) ;
F_3 ( V_2 , 0x5C ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
F_2 ( V_16 , V_2 , L_2 , V_8 ) ;
if ( V_2 -> V_17 . V_18 < 0 ) {
F_7 ( V_2 -> V_9 -> V_19 ,
L_3 ) ;
return - V_20 ;
}
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
int V_21 ;
int V_22 = V_23 ;
F_2 ( V_16 , V_2 , L_2 , V_8 ) ;
if ( V_2 -> V_17 . V_18 < 0 ) {
F_7 ( V_2 -> V_9 -> V_19 , L_3 ) ;
return - V_20 ;
}
if ( V_2 -> V_17 . V_24 < 0 ) {
F_7 ( V_2 -> V_9 -> V_19 , L_4 ) ;
return - V_20 ;
}
if ( V_25 && ( V_2 -> V_17 . V_26 < 0 ) ) {
F_7 ( V_2 -> V_9 -> V_19 , L_5 ) ;
return - V_20 ;
}
if ( V_25 )
V_22 = V_23 / 2 ;
for ( V_21 = 0 ; V_21 < V_22 ; V_21 ++ ) {
if ( V_2 -> V_17 . V_27 [ V_21 ] < 0 ) {
F_7 ( V_2 -> V_9 -> V_19 ,
L_6 ,
V_21 ) ;
return - V_20 ;
}
}
return 0 ;
}
static int F_9 ( struct V_28 * V_29 ,
struct V_30 * V_31 )
{
struct V_19 * V_32 ;
struct V_33 * V_9 ;
struct V_1 * V_2 ;
int V_34 ;
V_35 = V_36 ;
V_37 = V_38 ;
if ( V_29 )
V_32 = & V_29 -> V_32 ;
else
V_32 = & V_31 -> V_32 ;
F_10 ( V_32 , L_7 , V_8 ,
V_29 ? L_8 : L_9 ) ;
if ( V_39 ) {
if ( ! strcmp ( V_39 , L_10 ) ) {
if ( ! V_12 )
V_12 = 128 ;
if ( ! V_13 )
V_13 = 160 ;
if ( V_38 == 0 ) {
V_35 = V_40 ;
V_37 = F_11 ( V_40 ) ;
}
} else if ( ! strcmp ( V_39 , L_11 ) ) {
if ( ! V_12 )
V_12 = 176 ;
if ( ! V_13 )
V_13 = 220 ;
V_41 = 0 ;
if ( V_38 == 0 ) {
V_35 = V_42 ;
V_37 = F_11 ( V_42 ) ;
}
} else if ( ! strcmp ( V_39 , L_12 ) ) {
if ( ! V_12 )
V_12 = 176 ;
if ( ! V_13 )
V_13 = 220 ;
V_41 = 0 ;
V_43 = 16 ;
if ( V_38 == 0 ) {
V_35 = V_44 ;
V_37 = F_11 ( V_44 ) ;
}
} else if ( ! strcmp ( V_39 , L_13 ) ) {
if ( ! V_12 )
V_12 = 240 ;
if ( ! V_13 )
V_13 = 320 ;
V_41 = 1 ;
V_43 = 16 ;
if ( V_38 == 0 ) {
V_35 = V_45 ;
V_37 = F_11 ( V_45 ) ;
}
} else if ( ! strcmp ( V_39 , L_14 ) ) {
if ( ! V_12 )
V_12 = 240 ;
if ( ! V_13 )
V_13 = 320 ;
V_41 = 1 ;
V_43 = 16 ;
if ( V_38 == 0 ) {
V_35 = V_46 ;
V_37 = F_11 ( V_46 ) ;
}
} else if ( ! strcmp ( V_39 , L_15 ) ) {
if ( ! V_12 )
V_12 = 240 ;
if ( ! V_13 )
V_13 = 320 ;
V_41 = 0 ;
V_43 = 8 ;
if ( V_38 == 0 ) {
V_35 = V_47 ;
V_37 = F_11 ( V_47 ) ;
}
} else if ( ! strcmp ( V_39 , L_16 ) ) {
if ( ! V_12 )
V_12 = 240 ;
if ( ! V_13 )
V_13 = 320 ;
V_41 = 2 ;
V_43 = 16 ;
if ( V_38 == 0 ) {
V_35 = V_48 ;
V_37 = F_11 ( V_48 ) ;
}
} else if ( ! strcmp ( V_39 , L_17 ) ) {
if ( ! V_12 )
V_12 = 128 ;
if ( ! V_13 )
V_13 = 128 ;
V_41 = 3 ;
if ( V_38 == 0 ) {
V_35 = V_49 ;
V_37 = F_11 ( V_49 ) ;
}
} else {
F_7 ( V_32 , L_18 , V_39 ) ;
return - V_20 ;
}
}
if ( V_12 == 0 || V_13 == 0 ) {
F_7 ( V_32 , L_19 ) ;
return - V_20 ;
}
V_50 . V_12 = V_12 ;
V_50 . V_13 = V_13 ;
F_10 ( V_32 , L_20 , V_12 , V_13 ) ;
F_10 ( V_32 , L_21 , V_39 ? V_39 : L_22 ) ;
F_10 ( V_32 , L_23 , V_41 ) ;
F_10 ( V_32 , L_24 , V_43 ) ;
F_10 ( V_32 , L_25 , V_23 ) ;
V_9 = F_12 ( & V_50 , V_32 ) ;
if ( ! V_9 )
return - V_51 ;
V_2 = V_9 -> V_2 ;
if ( V_29 )
V_2 -> V_52 = V_29 ;
else
V_2 -> V_31 = V_31 ;
if ( ! V_2 -> V_53 )
V_2 -> V_53 = V_35 ;
V_2 -> V_54 . V_55 = V_56 ;
switch ( V_43 ) {
case 8 :
V_2 -> V_54 . V_57 = V_58 ;
break;
case 16 :
V_2 -> V_54 . V_57 = V_59 ;
break;
default:
F_7 ( V_32 ,
L_26 ,
V_43 ) ;
return - V_20 ;
}
if ( V_29 ) {
V_2 -> V_54 . V_60 = V_61 ;
switch ( V_23 ) {
case 8 :
V_2 -> V_54 . V_62 = V_63 ;
if ( ! V_2 -> V_64 )
V_2 -> V_54 . V_65 = F_6 ;
break;
case 9 :
if ( V_43 == 16 ) {
F_7 ( V_32 , L_27 , V_43 , V_23 ) ;
return - V_20 ;
}
V_2 -> V_54 . V_57 = V_66 ;
V_2 -> V_54 . V_62 = V_67 ;
V_29 -> V_68 = 9 ;
V_34 = V_29 -> V_69 -> V_70 ( V_29 ) ;
if ( V_34 ) {
F_13 ( V_32 ,
L_28 ) ;
V_29 -> V_68 = 8 ;
V_34 = V_29 -> V_69 -> V_70 ( V_29 ) ;
if ( V_34 )
goto V_71;
V_2 -> V_72 = F_14 ( V_2 -> V_9 -> V_19 ,
V_2 -> V_73 . V_74 + ( V_2 -> V_73 . V_74 / 8 ) + 8 ,
V_75 ) ;
if ( ! V_2 -> V_72 ) {
V_34 = - V_51 ;
goto V_71;
}
V_2 -> V_54 . V_60 = V_76 ;
}
break;
default:
F_7 ( V_32 , L_29 , V_23 ) ;
return - V_20 ;
}
} else {
V_2 -> V_54 . V_65 = F_8 ;
switch ( V_23 ) {
case 8 :
V_2 -> V_54 . V_60 = V_77 ;
V_2 -> V_54 . V_62 = V_63 ;
break;
case 16 :
V_2 -> V_54 . V_57 = V_78 ;
if ( V_25 )
V_2 -> V_54 . V_60 = V_79 ;
else
V_2 -> V_54 . V_60 = V_80 ;
V_2 -> V_54 . V_62 = V_81 ;
break;
default:
F_7 ( V_32 , L_30 , V_23 ) ;
return - V_20 ;
}
}
switch ( V_41 ) {
case 0 :
break;
case 1 :
V_2 -> V_54 . V_82 = F_1 ;
break;
case 2 :
V_2 -> V_54 . V_82 = F_4 ;
break;
case 3 :
V_2 -> V_54 . V_82 = F_5 ;
break;
default:
F_7 ( V_32 , L_31 ,
V_41 ) ;
return - V_20 ;
}
if ( ! V_83 )
V_2 -> V_54 . V_84 = V_85 ;
V_34 = F_15 ( V_9 ) ;
if ( V_34 < 0 )
goto V_71;
return 0 ;
V_71:
F_16 ( V_9 ) ;
return V_34 ;
}
static int F_17 ( struct V_19 * V_32 , struct V_33 * V_9 )
{
struct V_1 * V_2 ;
if ( ! V_9 )
return - V_20 ;
V_2 = V_9 -> V_2 ;
if ( V_2 )
F_2 ( V_86 , V_2 ,
L_2 , V_8 ) ;
F_18 ( V_9 ) ;
F_16 ( V_9 ) ;
return 0 ;
}
static int F_19 ( struct V_28 * V_52 )
{
return F_9 ( V_52 , NULL ) ;
}
static int F_20 ( struct V_28 * V_52 )
{
struct V_33 * V_9 = F_21 ( V_52 ) ;
return F_17 ( & V_52 -> V_32 , V_9 ) ;
}
static int F_22 ( struct V_30 * V_31 )
{
return F_9 ( NULL , V_31 ) ;
}
static int F_23 ( struct V_30 * V_31 )
{
struct V_33 * V_9 = F_24 ( V_31 ) ;
return F_17 ( & V_31 -> V_32 , V_9 ) ;
}
static int T_1 F_25 ( void )
{
int V_34 , V_87 ;
V_34 = F_26 ( & V_88 ) ;
V_87 = F_27 ( & V_89 ) ;
if ( V_34 < 0 )
return V_34 ;
return V_87 ;
}
static void T_2 F_28 ( void )
{
F_29 ( & V_88 ) ;
F_30 ( & V_89 ) ;
}
