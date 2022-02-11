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
switch ( V_15 ) {
case V_16 :
F_7 ( V_14 -> V_6 , V_17 ,
V_18 ,
V_18 ) ;
break;
default:
case V_19 :
F_7 ( V_14 -> V_6 , V_17 ,
V_18 , 0 ) ;
break;
}
return 0 ;
}
static int F_8 ( struct V_20 * V_21 ,
unsigned int V_22 )
{
struct V_5 * V_6 = V_21 -> V_6 ;
struct V_23 * V_24 = F_9 ( V_6 ) ;
switch ( V_22 & V_25 ) {
case V_26 :
case V_27 :
case V_28 :
V_24 -> V_29 = V_22 & V_25 ;
break;
default:
F_10 ( V_6 -> V_30 , L_1 ) ;
return - V_31 ;
}
switch ( V_22 & V_32 ) {
case V_33 :
V_24 -> V_34 = V_35 ;
break;
case V_36 :
V_24 -> V_34 = V_37 ;
break;
default:
F_10 ( V_6 -> V_30 , L_2 ) ;
return - V_31 ;
}
return 0 ;
}
static int F_11 ( struct V_20 * V_21 ,
int V_38 , unsigned int V_39 , int V_40 )
{
struct V_5 * V_6 = V_21 -> V_6 ;
struct V_23 * V_24 = F_9 ( V_6 ) ;
V_24 -> V_41 = V_39 ;
return 0 ;
}
static int F_12 ( struct V_42 * V_43 ,
struct V_44 * V_45 ,
struct V_20 * V_46 )
{
struct V_5 * V_6 = V_46 -> V_6 ;
struct V_23 * V_24 = F_9 ( V_6 ) ;
int V_47 ;
unsigned int V_48 ;
unsigned int V_49 ;
unsigned int V_50 ;
struct V_51 * V_52 = NULL ;
int V_53 = 0 ;
int V_54 , V_55 , V_56 ;
switch ( V_24 -> V_34 ) {
case V_35 :
return - V_31 ;
case V_57 :
V_52 = V_58 ;
V_53 = F_13 ( V_58 ) ;
break;
case V_37 :
V_52 = V_59 ;
V_53 = F_13 ( V_59 ) ;
break;
}
V_49 = F_14 ( V_45 ) ;
V_50 = V_24 -> V_41 / V_49 ;
for ( V_48 = 0 ; V_48 < V_53 ; V_48 ++ ) {
if ( V_52 [ V_48 ] . V_50 == V_50 )
break;
}
if ( V_48 == V_53 ) {
F_10 ( V_6 -> V_30 , L_3 ) ;
return - V_31 ;
}
V_54 = F_3 ( V_6 , V_60 ) ;
V_55 = F_3 ( V_6 , V_61 ) ;
V_54 &= ~ ( V_62 | V_63
| F_15 ( 7 ) ) ;
V_55 &= ~ ( F_16 ( 3 )
| V_64 ) ;
switch ( V_24 -> V_34 ) {
case V_35 :
V_54 |= V_62 ;
V_55 |= F_16 ( V_52 [ V_48 ] . V_65 ) ;
break;
case V_57 :
V_55 |= F_16 ( V_52 [ V_48 ] . V_65 ) ;
break;
case V_37 :
V_55 |= V_66 ;
break;
}
switch ( V_24 -> V_29 ) {
case V_26 :
V_54 |= V_63 ;
V_54 |= F_15 ( V_67 ) ;
break;
case V_27 :
V_54 |= F_15 ( V_68 ) ;
break;
case V_28 :
switch ( F_17 ( V_45 ) ) {
case 16 :
V_56 = V_69 ;
break;
case 18 :
V_56 = V_70 ;
break;
case 20 :
V_56 = V_71 ;
break;
case 24 :
V_56 = V_72 ;
break;
default:
F_10 ( V_6 -> V_30 , L_4 ) ;
return - V_31 ;
}
V_54 |= F_15 ( V_56 ) ;
break;
default:
F_10 ( V_6 -> V_30 , L_4 ) ;
return - V_31 ;
}
if ( V_52 [ V_48 ] . V_41 )
V_55 |= V_64 ;
V_47 = F_5 ( V_6 , V_60 , V_54 ) ;
if ( V_47 < 0 )
return V_47 ;
V_47 = F_5 ( V_6 , V_61 , V_55 ) ;
if ( V_47 < 0 )
return V_47 ;
return 0 ;
}
static int F_18 ( struct V_20 * V_46 , int V_73 )
{
struct V_5 * V_6 = V_46 -> V_6 ;
int V_74 ;
int V_75 = V_76 | V_77 ;
V_74 = F_3 ( V_6 , V_78 ) ;
if ( V_73 )
V_74 |= V_75 ;
else
V_74 &= ~ V_75 ;
return F_5 ( V_6 , V_78 , V_74 ) ;
}
static int F_19 ( struct V_5 * V_6 )
{
int V_47 , V_74 ;
V_74 = F_20 ( 1 )
| V_79 | F_21 ( 0 ) ;
V_47 = F_5 ( V_6 , V_80 , V_74 ) ;
if ( V_47 < 0 )
return V_47 ;
return 0 ;
}
int F_22 ( struct V_81 * V_30 , struct V_82 * V_82 )
{
struct V_23 * V_24 ;
unsigned int V_9 ;
int V_47 ;
if ( F_23 ( V_82 ) )
return F_24 ( V_82 ) ;
V_24 = F_25 ( V_30 , sizeof( struct V_23 ) ,
V_83 ) ;
if ( ! V_24 )
return - V_84 ;
F_26 ( V_30 , V_24 ) ;
V_47 = F_27 ( V_82 , V_85 , & V_9 ) ;
if ( V_47 < 0 ) {
F_10 ( V_30 , L_5 ) ;
goto error;
}
if ( ( V_9 != F_28 ( V_86 , V_87 ) ) &&
( V_9 != F_28 ( V_86 , V_88 ) ) ) {
F_10 ( V_30 , L_6 , V_9 ) ;
V_47 = - V_89 ;
goto error;
}
F_29 ( V_30 , L_7 ,
V_9 & V_90 ) ;
V_47 = F_30 ( V_30 ,
& V_91 , & V_92 , 1 ) ;
error:
return V_47 ;
}
