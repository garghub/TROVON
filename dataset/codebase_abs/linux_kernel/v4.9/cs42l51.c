static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned long V_7 = F_3 ( V_6 , V_8 ) & 3 ;
switch ( V_7 ) {
default:
case 0 :
V_4 -> V_7 . V_9 . V_10 [ 0 ] = 0 ;
break;
case 1 :
case 2 :
V_4 -> V_7 . V_9 . V_10 [ 0 ] = 1 ;
break;
case 3 :
V_4 -> V_7 . V_9 . V_10 [ 0 ] = 2 ;
break;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned char V_11 ;
switch ( V_4 -> V_7 . V_9 . V_10 [ 0 ] ) {
default:
case 0 :
V_11 = V_12 ;
break;
case 1 :
V_11 = V_13 ;
break;
case 2 :
V_11 = V_14 ;
break;
}
F_5 ( V_6 , V_8 , V_11 ) ;
return 1 ;
}
static int F_6 ( struct V_15 * V_16 ,
struct V_1 * V_2 , int V_17 )
{
struct V_5 * V_6 = F_7 ( V_16 -> V_18 ) ;
switch ( V_17 ) {
case V_19 :
F_8 ( V_6 , V_20 ,
V_21 ,
V_21 ) ;
break;
default:
case V_22 :
F_8 ( V_6 , V_20 ,
V_21 , 0 ) ;
break;
}
return 0 ;
}
static int F_9 ( struct V_23 * V_24 ,
unsigned int V_25 )
{
struct V_5 * V_6 = V_24 -> V_6 ;
struct V_26 * V_27 = F_10 ( V_6 ) ;
switch ( V_25 & V_28 ) {
case V_29 :
case V_30 :
case V_31 :
V_27 -> V_32 = V_25 & V_28 ;
break;
default:
F_11 ( V_6 -> V_33 , L_1 ) ;
return - V_34 ;
}
switch ( V_25 & V_35 ) {
case V_36 :
V_27 -> V_37 = V_38 ;
break;
case V_39 :
V_27 -> V_37 = V_40 ;
break;
default:
F_11 ( V_6 -> V_33 , L_2 ) ;
return - V_34 ;
}
return 0 ;
}
static int F_12 ( struct V_23 * V_24 ,
int V_41 , unsigned int V_42 , int V_43 )
{
struct V_5 * V_6 = V_24 -> V_6 ;
struct V_26 * V_27 = F_10 ( V_6 ) ;
V_27 -> V_44 = V_42 ;
return 0 ;
}
static int F_13 ( struct V_45 * V_46 ,
struct V_47 * V_48 ,
struct V_23 * V_49 )
{
struct V_5 * V_6 = V_49 -> V_6 ;
struct V_26 * V_27 = F_10 ( V_6 ) ;
int V_50 ;
unsigned int V_51 ;
unsigned int V_52 ;
unsigned int V_53 ;
struct V_54 * V_55 = NULL ;
int V_56 = 0 ;
int V_57 , V_58 , V_59 ;
switch ( V_27 -> V_37 ) {
case V_38 :
return - V_34 ;
case V_60 :
V_55 = V_61 ;
V_56 = F_14 ( V_61 ) ;
break;
case V_40 :
V_55 = V_62 ;
V_56 = F_14 ( V_62 ) ;
break;
}
V_52 = F_15 ( V_48 ) ;
V_53 = V_27 -> V_44 / V_52 ;
for ( V_51 = 0 ; V_51 < V_56 ; V_51 ++ ) {
if ( V_55 [ V_51 ] . V_53 == V_53 )
break;
}
if ( V_51 == V_56 ) {
F_11 ( V_6 -> V_33 , L_3 ) ;
return - V_34 ;
}
V_57 = F_3 ( V_6 , V_63 ) ;
V_58 = F_3 ( V_6 , V_64 ) ;
V_57 &= ~ ( V_65 | V_66
| F_16 ( 7 ) ) ;
V_58 &= ~ ( F_17 ( 3 )
| V_67 ) ;
switch ( V_27 -> V_37 ) {
case V_38 :
V_57 |= V_65 ;
V_58 |= F_17 ( V_55 [ V_51 ] . V_68 ) ;
break;
case V_60 :
V_58 |= F_17 ( V_55 [ V_51 ] . V_68 ) ;
break;
case V_40 :
V_58 |= V_69 ;
break;
}
switch ( V_27 -> V_32 ) {
case V_29 :
V_57 |= V_66 ;
V_57 |= F_16 ( V_70 ) ;
break;
case V_30 :
V_57 |= F_16 ( V_71 ) ;
break;
case V_31 :
switch ( F_18 ( V_48 ) ) {
case 16 :
V_59 = V_72 ;
break;
case 18 :
V_59 = V_73 ;
break;
case 20 :
V_59 = V_74 ;
break;
case 24 :
V_59 = V_75 ;
break;
default:
F_11 ( V_6 -> V_33 , L_4 ) ;
return - V_34 ;
}
V_57 |= F_16 ( V_59 ) ;
break;
default:
F_11 ( V_6 -> V_33 , L_4 ) ;
return - V_34 ;
}
if ( V_55 [ V_51 ] . V_44 )
V_58 |= V_67 ;
V_50 = F_5 ( V_6 , V_63 , V_57 ) ;
if ( V_50 < 0 )
return V_50 ;
V_50 = F_5 ( V_6 , V_64 , V_58 ) ;
if ( V_50 < 0 )
return V_50 ;
return 0 ;
}
static int F_19 ( struct V_23 * V_49 , int V_76 )
{
struct V_5 * V_6 = V_49 -> V_6 ;
int V_77 ;
int V_78 = V_79 | V_80 ;
V_77 = F_3 ( V_6 , V_81 ) ;
if ( V_76 )
V_77 |= V_78 ;
else
V_77 &= ~ V_78 ;
return F_5 ( V_6 , V_81 , V_77 ) ;
}
static int F_20 ( struct V_5 * V_6 )
{
int V_50 , V_77 ;
V_77 = F_21 ( 1 )
| V_82 | F_22 ( 0 ) ;
V_50 = F_5 ( V_6 , V_83 , V_77 ) ;
if ( V_50 < 0 )
return V_50 ;
return 0 ;
}
int F_23 ( struct V_84 * V_33 , struct V_85 * V_85 )
{
struct V_26 * V_27 ;
unsigned int V_11 ;
int V_50 ;
if ( F_24 ( V_85 ) )
return F_25 ( V_85 ) ;
V_27 = F_26 ( V_33 , sizeof( struct V_26 ) ,
V_86 ) ;
if ( ! V_27 )
return - V_87 ;
F_27 ( V_33 , V_27 ) ;
V_50 = F_28 ( V_85 , V_88 , & V_11 ) ;
if ( V_50 < 0 ) {
F_11 ( V_33 , L_5 ) ;
goto error;
}
if ( ( V_11 != F_29 ( V_89 , V_90 ) ) &&
( V_11 != F_29 ( V_89 , V_91 ) ) ) {
F_11 ( V_33 , L_6 , V_11 ) ;
V_50 = - V_92 ;
goto error;
}
F_30 ( V_33 , L_7 ,
V_11 & V_93 ) ;
V_50 = F_31 ( V_33 ,
& V_94 , & V_95 , 1 ) ;
error:
return V_50 ;
}
