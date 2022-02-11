static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 . V_8 ;
T_1 V_9 = 0 ;
T_1 V_10 = 0 ;
T_1 V_11 = 0 ;
if ( ! V_4 -> V_12 ) {
V_4 -> V_12 = F_2 ( sizeof( struct V_13 ) , V_14 ) ;
if ( ! V_4 -> V_12 )
return - V_15 ;
}
V_4 -> V_12 -> V_16 = F_3 ( V_6 , L_1 ) ;
if ( F_4 ( V_6 , L_2 ,
& V_4 -> V_12 -> V_17 ) ) {
V_4 -> V_12 -> V_17 = 1 ;
} else {
V_4 -> V_12 -> V_17 -- ;
}
if ( F_4 ( V_6 , L_3 ,
& V_4 -> V_12 -> V_18 ) ) {
V_4 -> V_12 -> V_18 = 1 ;
} else {
V_4 -> V_12 -> V_18 -- ;
}
F_4 ( V_6 , L_4 , & V_9 ) ;
for ( V_10 = 0 ; V_10 < 7 ; V_10 ++ ) {
if ( V_9 & ( 1 << V_10 ) ) {
switch ( V_10 ) {
case 0 :
V_4 -> V_12 -> V_19 [ V_11 ] = 4 ; break;
case 1 :
V_4 -> V_12 -> V_19 [ V_11 ] = 8 ; break;
case 2 :
V_4 -> V_12 -> V_19 [ V_11 ] = 16 ; break;
case 3 :
V_4 -> V_12 -> V_19 [ V_11 ] = 32 ; break;
case 4 :
V_4 -> V_12 -> V_19 [ V_11 ] = 64 ; break;
case 5 :
V_4 -> V_12 -> V_19 [ V_11 ] = 128 ; break;
case 6 :
V_4 -> V_12 -> V_19 [ V_11 ] = 256 ; break;
default:
break;
}
V_11 ++ ;
}
}
V_4 -> V_20 = 1 ;
V_4 -> V_21 -> V_22 = 1 ;
V_4 -> V_23 = 1 ;
V_4 -> V_24 = 1 ;
return 0 ;
}
static void * F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_25 * V_26 )
{
int V_27 ;
V_4 -> V_28 = F_6 ( & V_2 -> V_7 , L_5 ) ;
if ( F_7 ( V_4 -> V_28 ) ) {
F_8 ( & V_2 -> V_7 , L_6 ) ;
return F_9 ( V_4 -> V_28 ) ;
}
V_27 = F_10 ( V_4 -> V_28 ) ;
if ( V_27 < 0 ) {
F_8 ( & V_2 -> V_7 , L_7 ,
V_27 ) ;
return F_11 ( V_27 ) ;
}
V_4 -> V_29 = F_6 ( & V_2 -> V_7 , L_8 ) ;
if ( F_7 ( V_4 -> V_29 ) ) {
F_8 ( & V_2 -> V_7 , L_9 ) ;
V_27 = F_12 ( V_4 -> V_29 ) ;
goto V_30;
}
V_27 = F_10 ( V_4 -> V_29 ) ;
if ( V_27 < 0 ) {
F_8 ( & V_2 -> V_7 , L_10 ,
V_27 ) ;
goto V_30;
}
return NULL ;
V_30:
F_13 ( V_4 -> V_28 ) ;
return F_11 ( V_27 ) ;
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_31 * V_32 = F_15 ( V_2 ) ;
struct V_33 * V_34 = F_16 ( V_32 ) ;
F_13 ( V_34 -> V_35 -> V_29 ) ;
F_13 ( V_34 -> V_35 -> V_28 ) ;
return 0 ;
}
static void F_17 ( void * V_34 , unsigned int V_36 )
{
struct V_37 * V_38 = V_34 ;
unsigned long V_39 = 125000000 ;
bool V_40 = false ;
T_1 V_41 ;
int V_27 ;
switch ( V_36 ) {
case V_42 :
V_40 = true ;
V_39 = 125000000 ;
break;
case V_43 :
V_40 = true ;
V_39 = 25000000 ;
break;
case V_44 :
V_39 = 2500000 ;
break;
default:
F_8 ( V_38 -> V_7 , L_11 , V_36 ) ;
break;
}
if ( V_40 ) {
V_41 = F_18 ( V_38 -> V_45 + V_46 ) ;
V_41 |= V_47 ;
F_19 ( V_41 , V_38 -> V_45 + V_46 ) ;
F_20 ( 1 ) ;
V_41 = F_18 ( V_38 -> V_45 + V_48 ) ;
V_41 |= V_49 | V_50 ;
F_19 ( V_41 , V_38 -> V_45 + V_48 ) ;
V_27 = F_21 ( V_38 -> V_45 + V_51 ,
V_41 ,
V_41 & V_52 ,
1 , 10 ) ;
if ( V_27 < 0 ) {
F_8 ( V_38 -> V_7 , L_12 ) ;
goto V_53;
}
V_27 = F_21 ( V_38 -> V_45 + V_51 ,
V_41 ,
( V_41 & V_52 ) == 0 ,
20 , 200 ) ;
if ( V_27 < 0 ) {
F_8 ( V_38 -> V_7 , L_13 ) ;
goto V_53;
}
V_53:
V_41 = F_18 ( V_38 -> V_45 + V_46 ) ;
V_41 &= ~ V_47 ;
F_19 ( V_41 , V_38 -> V_45 + V_46 ) ;
} else {
V_41 = F_18 ( V_38 -> V_45 + V_48 ) ;
V_41 &= ~ V_50 ;
F_19 ( V_41 , V_38 -> V_45 + V_48 ) ;
}
V_27 = F_22 ( V_38 -> V_54 , V_39 ) ;
if ( V_27 < 0 )
F_8 ( V_38 -> V_7 , L_14 , V_27 ) ;
}
static int F_23 ( struct V_1 * V_2 , void * V_34 )
{
struct V_37 * V_38 = V_34 ;
unsigned long V_39 ;
T_1 V_41 ;
V_39 = F_24 ( V_38 -> V_55 ) ;
V_41 = ( V_39 / 1000000 ) - 1 ;
F_19 ( V_41 , V_38 -> V_45 + V_56 ) ;
return 0 ;
}
static void * F_25 ( struct V_1 * V_2 ,
struct V_3 * V_57 ,
struct V_25 * V_58 )
{
struct V_37 * V_38 ;
int V_27 ;
V_38 = F_26 ( & V_2 -> V_7 , sizeof( * V_38 ) , V_14 ) ;
if ( ! V_38 ) {
V_27 = - V_15 ;
goto error;
}
V_38 -> V_7 = & V_2 -> V_7 ;
V_38 -> V_45 = V_58 -> V_59 ;
V_38 -> V_60 = F_6 ( & V_2 -> V_7 , L_15 ) ;
if ( F_7 ( V_38 -> V_60 ) ) {
V_27 = F_12 ( V_38 -> V_60 ) ;
goto error;
}
V_27 = F_10 ( V_38 -> V_60 ) ;
if ( V_27 < 0 )
goto error;
V_38 -> V_55 = F_6 ( & V_2 -> V_7 , L_16 ) ;
if ( F_7 ( V_38 -> V_55 ) ) {
V_27 = F_12 ( V_38 -> V_55 ) ;
goto V_61;
}
V_57 -> V_28 = V_38 -> V_55 ;
V_27 = F_10 ( V_38 -> V_55 ) ;
if ( V_27 < 0 )
goto V_61;
V_38 -> V_62 = F_6 ( & V_2 -> V_7 , L_17 ) ;
if ( F_7 ( V_38 -> V_62 ) ) {
V_27 = F_12 ( V_38 -> V_62 ) ;
goto V_63;
}
V_27 = F_10 ( V_38 -> V_62 ) ;
if ( V_27 < 0 )
goto V_63;
V_38 -> V_54 = F_6 ( & V_2 -> V_7 , L_18 ) ;
if ( F_7 ( V_38 -> V_54 ) ) {
V_27 = F_12 ( V_38 -> V_54 ) ;
goto V_64;
}
V_27 = F_10 ( V_38 -> V_54 ) ;
if ( V_27 < 0 )
goto V_64;
V_38 -> V_65 = F_27 ( & V_2 -> V_7 , L_19 , V_66 ) ;
if ( F_7 ( V_38 -> V_65 ) ) {
V_27 = F_12 ( V_38 -> V_65 ) ;
goto V_67;
}
F_28 ( 2000 , 4000 ) ;
F_29 ( V_38 -> V_65 , 0 ) ;
V_38 -> V_68 = F_30 ( & V_2 -> V_7 , L_20 ) ;
if ( F_7 ( V_38 -> V_68 ) ) {
V_27 = F_12 ( V_38 -> V_68 ) ;
goto V_69;
}
V_27 = F_31 ( V_38 -> V_68 ) ;
if ( V_27 < 0 )
goto V_69;
F_28 ( 2000 , 4000 ) ;
V_27 = F_32 ( V_38 -> V_68 ) ;
if ( V_27 < 0 )
goto V_69;
F_28 ( 2000 , 4000 ) ;
V_57 -> V_70 = F_17 ;
V_57 -> V_71 = F_23 ;
V_57 -> V_72 = V_38 ;
V_27 = F_23 ( V_2 , V_38 ) ;
if ( V_27 < 0 )
goto V_65;
V_73:
return V_38 ;
V_65:
F_31 ( V_38 -> V_68 ) ;
V_69:
F_29 ( V_38 -> V_65 , 1 ) ;
V_67:
F_13 ( V_38 -> V_54 ) ;
V_64:
F_13 ( V_38 -> V_62 ) ;
V_63:
F_13 ( V_38 -> V_55 ) ;
V_61:
F_13 ( V_38 -> V_60 ) ;
error:
V_38 = F_11 ( V_27 ) ;
goto V_73;
}
static int F_33 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = F_34 ( & V_2 -> V_7 ) ;
F_31 ( V_38 -> V_68 ) ;
F_29 ( V_38 -> V_65 , 1 ) ;
F_13 ( V_38 -> V_54 ) ;
F_13 ( V_38 -> V_62 ) ;
F_13 ( V_38 -> V_55 ) ;
F_13 ( V_38 -> V_60 ) ;
return 0 ;
}
static int F_35 ( struct V_1 * V_2 )
{
const struct V_74 * V_57 ;
struct V_3 * V_4 ;
struct V_25 V_26 ;
struct V_75 * V_58 ;
void * V_34 ;
int V_76 ;
V_57 = F_36 ( & V_2 -> V_7 ) ;
memset ( & V_26 , 0 , sizeof( struct V_25 ) ) ;
V_26 . V_77 = F_37 ( V_2 , 0 ) ;
if ( V_26 . V_77 < 0 ) {
if ( V_26 . V_77 != - V_78 )
F_8 ( & V_2 -> V_7 ,
L_21 ) ;
return V_26 . V_77 ;
}
V_26 . V_79 = V_26 . V_77 ;
V_58 = F_38 ( V_2 , V_80 , 0 ) ;
V_26 . V_59 = F_39 ( & V_2 -> V_7 , V_58 ) ;
if ( F_7 ( V_26 . V_59 ) )
return F_12 ( V_26 . V_59 ) ;
V_4 = F_40 ( V_2 , & V_26 . V_81 ) ;
if ( F_7 ( V_4 ) )
return F_12 ( V_4 ) ;
V_34 = V_57 -> V_82 ( V_2 , V_4 , & V_26 ) ;
if ( F_7 ( V_34 ) ) {
V_76 = F_12 ( V_34 ) ;
F_8 ( & V_2 -> V_7 , L_22 , V_76 ) ;
goto V_83;
}
V_76 = F_1 ( V_2 , V_4 ) ;
if ( V_76 )
goto remove;
V_76 = F_41 ( & V_2 -> V_7 , V_4 , & V_26 ) ;
if ( V_76 )
goto remove;
return V_76 ;
remove:
V_57 -> remove ( V_2 ) ;
V_83:
F_42 ( V_2 , V_4 ) ;
return V_76 ;
}
static int F_43 ( struct V_1 * V_2 )
{
struct V_31 * V_32 = F_15 ( V_2 ) ;
struct V_33 * V_34 = F_16 ( V_32 ) ;
const struct V_74 * V_57 ;
int V_27 ;
V_57 = F_36 ( & V_2 -> V_7 ) ;
V_27 = F_44 ( & V_2 -> V_7 ) ;
if ( V_27 < 0 )
F_8 ( & V_2 -> V_7 , L_23 , V_27 ) ;
V_27 = V_57 -> remove ( V_2 ) ;
if ( V_27 < 0 )
F_8 ( & V_2 -> V_7 , L_24 , V_27 ) ;
F_42 ( V_2 , V_34 -> V_35 ) ;
return V_27 ;
}
