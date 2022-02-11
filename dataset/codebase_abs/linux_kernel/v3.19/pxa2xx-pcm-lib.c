int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 = V_6 -> V_9 ;
T_1 V_10 = F_2 ( V_4 ) ;
T_1 V_11 = F_3 ( V_4 ) ;
T_2 * V_12 ;
T_3 V_13 , V_14 ;
T_4 V_15 = V_16 | V_17 ;
switch ( V_8 -> V_4 -> V_18 ) {
case V_19 :
V_15 |= V_20 ;
break;
case V_21 :
V_15 |= V_22 ;
break;
case V_23 :
V_15 |= V_24 ;
break;
default:
break;
}
switch ( V_8 -> V_4 -> V_25 ) {
case 8 :
V_15 |= V_26 ;
break;
case 16 :
V_15 |= V_27 ;
break;
case 32 :
V_15 |= V_28 ;
break;
}
F_4 ( V_2 , & V_2 -> V_29 ) ;
V_6 -> V_30 = V_10 ;
V_12 = V_8 -> V_31 ;
V_14 = V_8 -> V_32 ;
V_13 = V_6 -> V_33 ;
do {
V_14 += sizeof( T_2 ) ;
V_12 -> V_34 = V_14 ;
if ( V_2 -> V_35 == V_36 ) {
V_12 -> V_37 = V_13 ;
V_12 -> V_38 = V_8 -> V_4 -> V_39 ;
} else {
V_12 -> V_37 = V_8 -> V_4 -> V_39 ;
V_12 -> V_38 = V_13 ;
}
if ( V_11 > V_10 )
V_11 = V_10 ;
V_12 -> V_15 = V_15 | V_11 | V_40 ;
V_12 ++ ;
V_13 += V_11 ;
} while ( V_10 -= V_11 );
V_12 [ - 1 ] . V_34 = V_8 -> V_32 ;
return 0 ;
}
int F_5 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_6 -> V_9 ;
if ( V_8 && V_8 -> V_4 && V_8 -> V_4 -> V_41 ) {
unsigned long V_42 = * ( unsigned long * ) V_8 -> V_4 -> V_41 ;
F_6 ( V_42 ) = 0 ;
}
F_4 ( V_2 , NULL ) ;
return 0 ;
}
int F_7 ( struct V_1 * V_2 , int V_43 )
{
struct V_7 * V_44 = V_2 -> V_6 -> V_9 ;
int V_45 = 0 ;
switch ( V_43 ) {
case V_46 :
F_8 ( V_44 -> V_47 ) = V_44 -> V_32 ;
F_9 ( V_44 -> V_47 ) = V_48 ;
break;
case V_49 :
case V_50 :
case V_51 :
F_9 ( V_44 -> V_47 ) &= ~ V_48 ;
break;
case V_52 :
F_9 ( V_44 -> V_47 ) |= V_48 ;
break;
case V_53 :
F_8 ( V_44 -> V_47 ) = V_44 -> V_32 ;
F_9 ( V_44 -> V_47 ) |= V_48 ;
break;
default:
V_45 = - V_54 ;
}
return V_45 ;
}
T_5
F_10 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_7 * V_44 = V_6 -> V_9 ;
T_3 V_55 = ( V_2 -> V_35 == V_36 ) ?
F_11 ( V_44 -> V_47 ) : F_12 ( V_44 -> V_47 ) ;
T_5 V_56 = F_13 ( V_6 , V_55 - V_6 -> V_33 ) ;
if ( V_56 == V_6 -> V_57 )
V_56 = 0 ;
return V_56 ;
}
int F_14 ( struct V_1 * V_2 )
{
struct V_7 * V_44 = V_2 -> V_6 -> V_9 ;
unsigned long V_42 ;
if ( ! V_44 || ! V_44 -> V_4 )
return 0 ;
if ( V_44 -> V_47 == - 1 )
return - V_54 ;
F_9 ( V_44 -> V_47 ) &= ~ V_48 ;
F_9 ( V_44 -> V_47 ) = 0 ;
F_15 ( V_44 -> V_47 ) = 0 ;
V_42 = * ( unsigned long * ) V_44 -> V_4 -> V_41 ;
F_6 ( V_42 ) = V_44 -> V_47 | V_58 ;
return 0 ;
}
void F_16 ( int V_47 , void * V_59 )
{
struct V_1 * V_2 = V_59 ;
int V_60 ;
V_60 = F_9 ( V_47 ) ;
F_9 ( V_47 ) = V_60 & ~ V_61 ;
if ( V_60 & V_62 ) {
F_17 ( V_2 ) ;
} else {
F_18 ( V_63 L_1 ,
V_47 , V_60 ) ;
F_19 ( V_2 ) ;
}
}
int F_20 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 ;
int V_45 ;
V_6 -> V_64 = V_65 ;
V_45 = F_21 ( V_6 , 0 ,
V_66 , 32 ) ;
if ( V_45 )
goto V_67;
V_45 = F_21 ( V_6 , 0 ,
V_68 , 32 ) ;
if ( V_45 )
goto V_67;
V_45 = F_22 ( V_6 ,
V_69 ) ;
if ( V_45 < 0 )
goto V_67;
V_45 = - V_70 ;
V_8 = F_23 ( sizeof( * V_8 ) , V_71 ) ;
if ( ! V_8 )
goto V_67;
V_8 -> V_31 =
F_24 ( V_2 -> V_72 -> V_73 -> V_74 , V_75 ,
& V_8 -> V_32 , V_71 ) ;
if ( ! V_8 -> V_31 )
goto V_76;
V_8 -> V_47 = - 1 ;
V_6 -> V_9 = V_8 ;
return 0 ;
V_76:
F_25 ( V_8 ) ;
V_67:
return V_45 ;
}
int F_26 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 = V_6 -> V_9 ;
F_27 ( V_2 -> V_72 -> V_73 -> V_74 , V_75 ,
V_8 -> V_31 , V_8 -> V_32 ) ;
F_25 ( V_8 ) ;
return 0 ;
}
int F_28 ( struct V_1 * V_2 ,
struct V_77 * V_78 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
return F_29 ( V_2 -> V_72 -> V_73 -> V_74 , V_78 ,
V_6 -> V_79 ,
V_6 -> V_33 ,
V_6 -> V_30 ) ;
}
int F_30 ( struct V_80 * V_72 , int V_35 )
{
struct V_1 * V_2 = V_72 -> V_81 [ V_35 ] . V_2 ;
struct V_82 * V_83 = & V_2 -> V_29 ;
T_1 V_84 = V_65 . V_85 ;
V_83 -> V_74 . type = V_86 ;
V_83 -> V_74 . V_74 = V_72 -> V_73 -> V_74 ;
V_83 -> V_9 = NULL ;
V_83 -> V_87 = F_24 ( V_72 -> V_73 -> V_74 , V_84 ,
& V_83 -> V_39 , V_71 ) ;
if ( ! V_83 -> V_87 )
return - V_70 ;
V_83 -> V_88 = V_84 ;
return 0 ;
}
void F_31 ( struct V_80 * V_72 )
{
struct V_1 * V_2 ;
struct V_82 * V_83 ;
int V_35 ;
for ( V_35 = 0 ; V_35 < 2 ; V_35 ++ ) {
V_2 = V_72 -> V_81 [ V_35 ] . V_2 ;
if ( ! V_2 )
continue;
V_83 = & V_2 -> V_29 ;
if ( ! V_83 -> V_87 )
continue;
F_27 ( V_72 -> V_73 -> V_74 , V_83 -> V_88 ,
V_83 -> V_87 , V_83 -> V_39 ) ;
V_83 -> V_87 = NULL ;
}
}
