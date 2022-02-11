static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned long V_7 = F_3 ( V_6 , V_8 ) & 3 ;
switch ( V_7 ) {
default:
case 0 :
V_4 -> V_7 . integer . V_7 [ 0 ] = 0 ;
break;
case 1 :
case 2 :
V_4 -> V_7 . integer . V_7 [ 0 ] = 1 ;
break;
case 3 :
V_4 -> V_7 . integer . V_7 [ 0 ] = 2 ;
break;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned char V_9 ;
switch ( V_4 -> V_7 . integer . V_7 [ 0 ] ) {
default:
case 0 :
V_9 = V_10 ;
break;
case 1 :
V_9 = V_11 ;
break;
case 2 :
V_9 = V_12 ;
break;
}
F_5 ( V_6 , V_8 , V_9 ) ;
return 1 ;
}
static int F_6 ( struct V_13 * V_14 ,
struct V_1 * V_2 , int V_15 )
{
struct V_5 * V_6 = F_7 ( V_14 -> V_16 ) ;
switch ( V_15 ) {
case V_17 :
F_8 ( V_6 , V_18 ,
V_19 ,
V_19 ) ;
break;
default:
case V_20 :
F_8 ( V_6 , V_18 ,
V_19 , 0 ) ;
break;
}
return 0 ;
}
static int F_9 ( struct V_21 * V_22 ,
unsigned int V_23 )
{
struct V_5 * V_6 = V_22 -> V_6 ;
struct V_24 * V_25 = F_10 ( V_6 ) ;
switch ( V_23 & V_26 ) {
case V_27 :
case V_28 :
case V_29 :
V_25 -> V_30 = V_23 & V_26 ;
break;
default:
F_11 ( V_6 -> V_31 , L_1 ) ;
return - V_32 ;
}
switch ( V_23 & V_33 ) {
case V_34 :
V_25 -> V_35 = V_36 ;
break;
case V_37 :
V_25 -> V_35 = V_38 ;
break;
default:
F_11 ( V_6 -> V_31 , L_2 ) ;
return - V_32 ;
}
return 0 ;
}
static int F_12 ( struct V_21 * V_22 ,
int V_39 , unsigned int V_40 , int V_41 )
{
struct V_5 * V_6 = V_22 -> V_6 ;
struct V_24 * V_25 = F_10 ( V_6 ) ;
V_25 -> V_42 = V_40 ;
return 0 ;
}
static int F_13 ( struct V_43 * V_44 ,
struct V_45 * V_46 ,
struct V_21 * V_47 )
{
struct V_5 * V_6 = V_47 -> V_6 ;
struct V_24 * V_25 = F_10 ( V_6 ) ;
int V_48 ;
unsigned int V_49 ;
unsigned int V_50 ;
unsigned int V_51 ;
struct V_52 * V_53 = NULL ;
int V_54 = 0 ;
int V_55 , V_56 , V_57 ;
switch ( V_25 -> V_35 ) {
case V_36 :
return - V_32 ;
case V_58 :
V_53 = V_59 ;
V_54 = F_14 ( V_59 ) ;
break;
case V_38 :
V_53 = V_60 ;
V_54 = F_14 ( V_60 ) ;
break;
}
V_50 = F_15 ( V_46 ) ;
V_51 = V_25 -> V_42 / V_50 ;
for ( V_49 = 0 ; V_49 < V_54 ; V_49 ++ ) {
if ( V_53 [ V_49 ] . V_51 == V_51 )
break;
}
if ( V_49 == V_54 ) {
F_11 ( V_6 -> V_31 , L_3 ) ;
return - V_32 ;
}
V_55 = F_3 ( V_6 , V_61 ) ;
V_56 = F_3 ( V_6 , V_62 ) ;
V_55 &= ~ ( V_63 | V_64
| F_16 ( 7 ) ) ;
V_56 &= ~ ( F_17 ( 3 )
| V_65 ) ;
switch ( V_25 -> V_35 ) {
case V_36 :
V_55 |= V_63 ;
V_56 |= F_17 ( V_53 [ V_49 ] . V_66 ) ;
break;
case V_58 :
V_56 |= F_17 ( V_53 [ V_49 ] . V_66 ) ;
break;
case V_38 :
V_56 |= V_67 ;
break;
}
switch ( V_25 -> V_30 ) {
case V_27 :
V_55 |= V_64 ;
V_55 |= F_16 ( V_68 ) ;
break;
case V_28 :
V_55 |= F_16 ( V_69 ) ;
break;
case V_29 :
switch ( F_18 ( V_46 ) ) {
case 16 :
V_57 = V_70 ;
break;
case 18 :
V_57 = V_71 ;
break;
case 20 :
V_57 = V_72 ;
break;
case 24 :
V_57 = V_73 ;
break;
default:
F_11 ( V_6 -> V_31 , L_4 ) ;
return - V_32 ;
}
V_55 |= F_16 ( V_57 ) ;
break;
default:
F_11 ( V_6 -> V_31 , L_4 ) ;
return - V_32 ;
}
if ( V_53 [ V_49 ] . V_42 )
V_56 |= V_65 ;
V_48 = F_5 ( V_6 , V_61 , V_55 ) ;
if ( V_48 < 0 )
return V_48 ;
V_48 = F_5 ( V_6 , V_62 , V_56 ) ;
if ( V_48 < 0 )
return V_48 ;
return 0 ;
}
static int F_19 ( struct V_21 * V_47 , int V_74 )
{
struct V_5 * V_6 = V_47 -> V_6 ;
int V_75 ;
int V_76 = V_77 | V_78 ;
V_75 = F_3 ( V_6 , V_79 ) ;
if ( V_74 )
V_75 |= V_76 ;
else
V_75 &= ~ V_76 ;
return F_5 ( V_6 , V_79 , V_75 ) ;
}
static int F_20 ( struct V_5 * V_6 )
{
int V_48 , V_75 ;
V_75 = F_21 ( 1 )
| V_80 | F_22 ( 0 ) ;
V_48 = F_5 ( V_6 , V_81 , V_75 ) ;
if ( V_48 < 0 )
return V_48 ;
return 0 ;
}
int F_23 ( struct V_82 * V_31 , struct V_83 * V_83 )
{
struct V_24 * V_25 ;
unsigned int V_9 ;
int V_48 ;
if ( F_24 ( V_83 ) )
return F_25 ( V_83 ) ;
V_25 = F_26 ( V_31 , sizeof( struct V_24 ) ,
V_84 ) ;
if ( ! V_25 )
return - V_85 ;
F_27 ( V_31 , V_25 ) ;
V_48 = F_28 ( V_83 , V_86 , & V_9 ) ;
if ( V_48 < 0 ) {
F_11 ( V_31 , L_5 ) ;
goto error;
}
if ( ( V_9 != F_29 ( V_87 , V_88 ) ) &&
( V_9 != F_29 ( V_87 , V_89 ) ) ) {
F_11 ( V_31 , L_6 , V_9 ) ;
V_48 = - V_90 ;
goto error;
}
F_30 ( V_31 , L_7 ,
V_9 & V_91 ) ;
V_48 = F_31 ( V_31 ,
& V_92 , & V_93 , 1 ) ;
error:
return V_48 ;
}
