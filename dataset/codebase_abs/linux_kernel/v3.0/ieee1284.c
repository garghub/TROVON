static void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 -> V_4 . V_5 ) ;
}
static void F_3 ( unsigned long V_6 )
{
F_1 ( V_7 [ V_6 % V_8 ] ) ;
}
int F_4 ( struct V_1 * V_2 , signed long V_9 )
{
int V_10 ;
struct V_11 V_12 ;
if ( ! V_2 -> V_3 -> V_13 -> V_9 )
return 1 ;
F_5 ( & V_12 ) ;
V_12 . V_14 = V_15 + V_9 ;
V_12 . V_16 = F_3 ;
V_7 [ V_2 -> V_17 % V_8 ] = V_2 ;
V_12 . V_18 = V_2 -> V_17 ;
F_6 ( & V_12 ) ;
V_10 = F_7 ( & V_2 -> V_3 -> V_4 . V_5 ) ;
if ( ! F_8 ( & V_12 ) && ! V_10 )
V_10 = 1 ;
F_9 ( & V_12 ) ;
return V_10 ;
}
int F_10 ( struct V_1 * V_2 ,
unsigned char V_19 ,
unsigned char V_20 ,
int V_21 )
{
int V_22 = V_21 / 5 + 2 ;
int V_23 ;
unsigned char V_24 ;
for ( V_23 = 0 ; V_23 < V_22 ; V_23 ++ ) {
V_24 = F_11 ( V_2 ) ;
if ( ( V_24 & V_19 ) == V_20 )
return 0 ;
if ( F_12 ( V_25 ) )
return - V_26 ;
if ( F_13 () )
break;
if ( V_23 >= 2 )
F_14 ( 5 ) ;
}
return 1 ;
}
int F_15 ( struct V_1 * V_2 ,
unsigned char V_19 ,
unsigned char V_20 )
{
int V_10 ;
int V_21 ;
unsigned long V_27 ;
unsigned char V_24 ;
V_21 = V_2 -> V_3 -> V_28 ;
if ( ! V_2 -> V_3 -> V_13 -> V_9 )
V_21 = 35000 ;
V_10 = F_10 ( V_2 , V_19 , V_20 , V_21 ) ;
if ( V_10 != 1 )
return V_10 ;
if ( ! V_2 -> V_3 -> V_13 -> V_9 )
return 1 ;
V_27 = V_15 + F_16 ( 40 ) ;
while ( F_17 ( V_15 , V_27 ) ) {
if ( F_12 ( V_25 ) )
return - V_26 ;
if ( ( V_10 = F_4 ( V_2 , F_16 ( 10 ) ) ) < 0 )
return V_10 ;
V_24 = F_11 ( V_2 ) ;
if ( ( V_24 & V_19 ) == V_20 )
return 0 ;
if ( ! V_10 ) {
F_18 ( F_16 ( 10 ) ) ;
}
}
return 1 ;
}
static void F_19 ( struct V_1 * V_2 )
{
int V_29 ;
V_2 = V_2 -> V_3 ;
switch ( V_2 -> V_4 . V_30 ) {
case V_31 :
case V_32 :
case V_33 :
F_20 ( V_2 , V_34 , 0 ) ;
F_14 ( 50 ) ;
F_20 ( V_2 ,
V_35
| V_34 ,
V_35
| V_34 ) ;
break;
case V_36 :
case V_37 :
case V_38 :
if ( V_2 -> V_4 . V_39 != V_40 ) {
F_20 ( V_2 ,
V_34
| V_41 ,
V_34
| V_41 ) ;
V_29 = F_15 ( V_2 ,
V_42 ,
V_42 ) ;
if ( V_29 )
F_21 ( V_43 L_1 ,
V_2 -> V_44 ) ;
F_22 ( V_2 ) ;
F_21 ( V_45 L_2 ,
V_2 -> V_44 ) ;
V_2 -> V_4 . V_39 = V_40 ;
}
default:
F_20 ( V_2 ,
V_35
| V_41 ,
V_35 ) ;
V_29 = F_15 ( V_2 , V_46 , 0 ) ;
if ( V_29 )
F_21 ( V_43 L_3 ,
V_2 -> V_44 ) ;
F_20 ( V_2 ,
V_41 ,
V_41 ) ;
V_29 = F_15 ( V_2 ,
V_46 ,
V_46 ) ;
if ( V_29 )
F_21 ( V_43 L_4 ,
V_2 -> V_44 ) ;
F_20 ( V_2 , V_41 , 0 ) ;
}
V_2 -> V_4 . V_30 = V_47 ;
V_2 -> V_4 . V_39 = V_40 ;
F_21 ( V_45 L_5 ,
V_2 -> V_44 ) ;
}
int F_23 ( struct V_1 * V_2 , int V_30 )
{
#ifndef F_24
if ( V_30 == V_47 )
return 0 ;
F_25 ( V_48 L_6 ) ;
return - 1 ;
#else
int V_49 = V_30 & ~ V_50 ;
int V_29 ;
unsigned char V_51 ;
V_2 = V_2 -> V_3 ;
if ( V_2 -> V_4 . V_30 == V_30 )
return 0 ;
if ( ( V_2 -> V_4 . V_30 & ~ V_50 ) == ( V_30 & ~ V_50 ) ) {
V_2 -> V_4 . V_30 = V_30 ;
return 0 ;
}
if ( V_2 -> V_4 . V_30 != V_47 )
F_19 ( V_2 ) ;
if ( V_30 == V_47 )
return 0 ;
switch ( V_30 ) {
case V_38 :
V_49 = V_36 ;
break;
case V_32 :
case V_33 :
V_49 = V_31 ;
break;
case V_52 :
return - V_53 ;
}
if ( V_30 & V_54 )
V_49 = 1 << 7 ;
V_2 -> V_4 . V_39 = V_55 ;
F_20 ( V_2 ,
V_56
| V_41
| V_35 ,
V_35 ) ;
F_14 ( 1 ) ;
F_22 ( V_2 ) ;
F_26 ( V_2 , V_49 ) ;
F_14 ( 400 ) ;
F_20 ( V_2 ,
V_35
| V_41 ,
V_41 ) ;
if ( F_15 ( V_2 ,
V_57
| V_58
| V_42
| V_46 ,
V_57
| V_58
| V_42 ) ) {
F_20 ( V_2 ,
V_35
| V_41 ,
V_35 ) ;
F_21 ( V_45
L_7 ,
V_2 -> V_44 , F_11 ( V_2 ) ) ;
V_2 -> V_4 . V_39 = V_40 ;
return - 1 ;
}
F_20 ( V_2 ,
V_56 ,
V_56 ) ;
F_14 ( 5 ) ;
F_20 ( V_2 ,
V_56
| V_41 ,
0 ) ;
if ( F_15 ( V_2 ,
V_46 ,
V_46 ) ) {
F_21 ( V_45
L_8 ,
V_2 -> V_44 , V_30 , V_2 -> V_59 -> V_60 ( V_2 ) ) ;
F_19 ( V_2 ) ;
return 1 ;
}
V_51 = F_11 ( V_2 ) & V_58 ;
if ( V_30 && ! V_51 ) {
F_21 ( V_45 L_9 ,
V_2 -> V_44 , V_30 ) ;
F_19 ( V_2 ) ;
return 1 ;
}
if ( V_30 & V_54 ) {
V_49 = V_30 & 0x7f ;
F_14 ( 1 ) ;
F_26 ( V_2 , V_49 ) ;
F_14 ( 1 ) ;
F_20 ( V_2 ,
V_56 ,
V_56 ) ;
if ( F_15 ( V_2 , V_46 , 0 ) ) {
F_21 ( V_45
L_10 ,
V_2 -> V_44 ) ;
F_19 ( V_2 ) ;
return 1 ;
}
F_20 ( V_2 ,
V_56 ,
0 ) ;
if ( F_15 ( V_2 ,
V_46 ,
V_46 ) ) {
F_21 ( V_45
L_8 ,
V_2 -> V_44 , V_30 ,
V_2 -> V_59 -> V_60 ( V_2 ) ) ;
F_19 ( V_2 ) ;
return 1 ;
}
V_51 = F_11 ( V_2 ) & V_58 ;
if ( ! V_51 ) {
F_21 ( V_45 L_11
L_12 , V_2 -> V_44 , V_30 ) ;
F_19 ( V_2 ) ;
return 1 ;
}
}
F_21 ( V_45 L_13 , V_2 -> V_44 , V_30 ) ;
V_2 -> V_4 . V_30 = V_30 ;
if ( ! ( V_30 & V_54 ) && ( V_49 & V_36 ) ) {
V_2 -> V_4 . V_39 = V_61 ;
F_20 ( V_2 ,
V_41 ,
V_41 ) ;
V_29 = F_15 ( V_2 ,
V_42 ,
V_42 ) ;
if ( V_29 ) {
F_21 ( V_43 L_14 ,
V_2 -> V_44 ) ;
}
V_2 -> V_4 . V_39 = V_40 ;
F_21 ( V_45 L_2 ,
V_2 -> V_44 ) ;
} else switch ( V_30 ) {
case V_62 :
case V_63 :
V_2 -> V_4 . V_39 = V_64 ;
break;
default:
V_2 -> V_4 . V_39 = V_40 ;
}
return 0 ;
#endif
}
static int F_27 ( struct V_1 * V_2 )
{
if ( F_11 ( V_2 ) & V_57 )
return - 1 ;
V_2 -> V_59 -> V_65 ( V_2 , V_41 , 0 ) ;
V_2 -> V_4 . V_39 = V_66 ;
return 0 ;
}
void F_28 ( void * V_67 )
{
struct V_1 * V_2 = V_67 ;
F_1 ( V_2 ) ;
#ifdef F_24
if ( V_2 -> V_4 . V_39 == V_64 ) {
F_21 ( V_45 L_15 , V_2 -> V_44 ) ;
F_27 ( V_2 ) ;
}
#endif
}
T_1 F_29 ( struct V_1 * V_2 , const void * V_68 , T_2 V_69 )
{
#ifndef F_24
return V_2 -> V_59 -> V_70 ( V_2 , V_68 , V_69 , 0 ) ;
#else
T_1 V_71 ;
int V_30 = V_2 -> V_4 . V_30 ;
int V_72 = V_30 & V_50 ;
T_2 (* F_30) ( struct V_1 * , const void * , T_2 , int );
V_30 &= ~ ( V_73 | V_50 ) ;
switch ( V_30 ) {
case V_62 :
case V_63 :
F_23 ( V_2 , V_47 ) ;
case V_47 :
F_21 ( V_45 L_16 ,
V_2 -> V_44 ) ;
F_30 = V_2 -> V_59 -> V_70 ;
break;
case V_31 :
F_21 ( V_45 L_17 , V_2 -> V_44 ) ;
if ( V_72 ) {
F_30 = V_2 -> V_59 -> V_74 ;
} else {
F_30 = V_2 -> V_59 -> V_75 ;
}
break;
case V_33 :
F_21 ( V_45 L_18 ,
V_2 -> V_44 ) ;
if ( V_72 ) {
F_30 = V_76 ;
} else {
F_30 = V_77 ;
}
break;
case V_36 :
case V_37 :
F_21 ( V_45 L_19 , V_2 -> V_44 ) ;
if ( V_72 ) {
F_30 = V_2 -> V_59 -> V_78 ;
} else {
F_30 = V_2 -> V_59 -> V_79 ;
}
break;
case V_38 :
F_21 ( V_45 L_20 ,
V_2 -> V_44 ) ;
if ( V_72 ) {
F_30 = V_80 ;
} else {
F_30 = V_81 ;
}
break;
default:
F_21 ( V_45 L_21 , V_2 -> V_44 ,
V_2 -> V_4 . V_30 ) ;
return - V_53 ;
}
V_71 = (* F_30) ( V_2 , V_68 , V_69 , 0 ) ;
F_21 ( V_45 L_22 , V_2 -> V_44 , V_71 , V_69 ) ;
return V_71 ;
#endif
}
T_1 F_31 ( struct V_1 * V_2 , void * V_68 , T_2 V_69 )
{
#ifndef F_24
F_25 ( V_48 L_6 ) ;
return - V_82 ;
#else
int V_30 = V_2 -> V_3 -> V_4 . V_30 ;
int V_72 = V_30 & V_50 ;
T_2 (* F_30) ( struct V_1 * , void * , T_2 , int );
V_30 &= ~ ( V_73 | V_50 ) ;
switch ( V_30 ) {
case V_47 :
if ( ( V_2 -> V_3 -> V_83 & V_84 ) &&
! F_23 ( V_2 , V_63 ) ) {
F_21 ( V_45 L_23 , V_2 -> V_44 ) ;
F_30 = V_2 -> V_59 -> V_85 ;
break;
}
if ( F_23 ( V_2 , V_62 ) ) {
return - V_86 ;
}
case V_62 :
F_21 ( V_45 L_24 , V_2 -> V_44 ) ;
F_30 = V_2 -> V_59 -> V_87 ;
break;
case V_63 :
F_21 ( V_45 L_23 , V_2 -> V_44 ) ;
F_30 = V_2 -> V_59 -> V_85 ;
break;
case V_31 :
F_21 ( V_45 L_17 , V_2 -> V_44 ) ;
if ( V_72 ) {
F_30 = V_2 -> V_59 -> V_88 ;
} else {
F_30 = V_2 -> V_59 -> V_89 ;
}
break;
case V_33 :
F_21 ( V_45 L_18 ,
V_2 -> V_44 ) ;
if ( V_72 ) {
F_30 = V_90 ;
} else {
F_30 = V_91 ;
}
break;
case V_36 :
case V_37 :
F_21 ( V_45 L_19 , V_2 -> V_44 ) ;
F_30 = V_2 -> V_59 -> V_92 ;
break;
case V_38 :
F_21 ( V_45 L_20 ,
V_2 -> V_44 ) ;
F_30 = V_93 ;
break;
default:
F_21 ( V_45 L_21 , V_2 -> V_44 ,
V_2 -> V_3 -> V_4 . V_30 ) ;
return - V_53 ;
}
return (* F_30) ( V_2 , V_68 , V_69 , 0 ) ;
#endif
}
long F_32 ( struct V_94 * V_95 , long V_96 )
{
long int V_97 = V_95 -> V_9 ;
V_95 -> V_9 = V_96 ;
if ( V_95 -> V_2 -> V_3 -> V_13 == V_95 )
F_1 ( V_95 -> V_2 ) ;
return V_97 ;
}
