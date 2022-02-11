T_1 F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = 0 ;
if ( V_2 -> V_4 == V_5 ) {
switch ( V_2 -> V_6 ) {
case V_7 :
case V_8 :
case V_9 :
case V_10 :
case V_11 :
case V_12 :
case V_13 :
case V_14 :
case V_15 :
case V_16 :
V_2 -> V_17 . type = V_18 ;
break;
case V_19 :
case V_20 :
V_2 -> V_17 . type = V_21 ;
break;
default:
V_2 -> V_17 . type = V_22 ;
break;
}
} else {
V_3 = V_23 ;
}
F_2 ( V_2 , L_1 ,
V_2 -> V_17 . type , V_3 ) ;
return V_3 ;
}
void F_3 ( struct V_1 * V_2 , enum V_24 V_25 , void * V_26 ,
void * V_27 , T_2 V_28 )
{
struct V_29 * V_30 = (struct V_29 * ) V_26 ;
T_2 V_31 = F_4 ( V_30 -> V_32 ) ;
T_3 * V_33 = ( T_3 * ) V_27 ;
T_2 V_34 = 0 ;
if ( ( ! ( V_25 & V_2 -> V_35 ) ) || ( V_26 == NULL ) )
return;
F_5 ( V_2 , V_25 ,
L_2 ,
F_4 ( V_30 -> V_36 ) ,
F_4 ( V_30 -> V_37 ) ,
F_4 ( V_30 -> V_32 ) ,
F_4 ( V_30 -> V_38 ) ) ;
F_5 ( V_2 , V_25 , L_3 ,
F_6 ( V_30 -> V_39 ) ,
F_6 ( V_30 -> V_40 ) ) ;
F_5 ( V_2 , V_25 , L_4 ,
F_6 ( V_30 -> V_41 . V_42 . V_43 ) ,
F_6 ( V_30 -> V_41 . V_42 . V_44 ) ) ;
F_5 ( V_2 , V_25 , L_5 ,
F_6 ( V_30 -> V_41 . V_45 . V_46 ) ,
F_6 ( V_30 -> V_41 . V_45 . V_47 ) ) ;
if ( ( V_27 != NULL ) && ( V_30 -> V_32 != 0 ) ) {
F_5 ( V_2 , V_25 , L_6 ) ;
if ( V_28 < V_31 )
V_31 = V_28 ;
for ( V_34 = 0 ; V_34 < ( V_31 - 16 ) ; V_34 += 16 )
F_5 ( V_2 , V_25 ,
L_7 ,
V_34 , V_33 [ V_34 ] , V_33 [ V_34 + 1 ] , V_33 [ V_34 + 2 ] ,
V_33 [ V_34 + 3 ] , V_33 [ V_34 + 4 ] , V_33 [ V_34 + 5 ] ,
V_33 [ V_34 + 6 ] , V_33 [ V_34 + 7 ] , V_33 [ V_34 + 8 ] ,
V_33 [ V_34 + 9 ] , V_33 [ V_34 + 10 ] , V_33 [ V_34 + 11 ] ,
V_33 [ V_34 + 12 ] , V_33 [ V_34 + 13 ] , V_33 [ V_34 + 14 ] ,
V_33 [ V_34 + 15 ] ) ;
if ( V_34 < V_31 ) {
char V_48 [ 80 ] ;
int V_49 = 0 ;
memset ( V_48 , 0 , sizeof( V_48 ) ) ;
V_49 += sprintf ( V_48 , L_8 , V_34 ) ;
while ( V_34 < V_31 )
V_49 += sprintf ( & V_48 [ V_49 ] , L_9 , V_33 [ V_34 ++ ] ) ;
F_5 ( V_2 , V_25 , L_10 , V_48 ) ;
}
}
}
bool F_7 ( struct V_1 * V_2 )
{
if ( V_2 -> V_50 . V_51 . V_31 )
return ! ! ( F_8 ( V_2 , V_2 -> V_50 . V_51 . V_31 ) &
V_52 ) ;
else
return false ;
}
T_1 F_9 ( struct V_1 * V_2 ,
bool V_53 )
{
struct V_29 V_26 ;
struct V_54 * V_55 =
(struct V_54 * ) & V_26 . V_41 . V_56 ;
T_1 V_3 ;
F_10 ( & V_26 ,
V_57 ) ;
if ( V_53 )
V_55 -> V_58 = F_11 ( V_59 ) ;
V_3 = F_12 ( V_2 , & V_26 , NULL , 0 , NULL ) ;
return V_3 ;
}
T_1 F_13 ( struct V_1 * V_2 ,
enum V_60 V_61 ,
T_1 V_62 ,
T_3 * V_63 , T_2 V_64 ,
struct V_65 * V_66 )
{
struct V_29 V_26 ;
struct V_65 V_67 ;
T_1 V_3 ;
F_10 ( & V_26 , V_68 ) ;
V_26 . V_37 |= F_14 ( ( T_2 ) V_69 ) ;
V_26 . V_39 = F_11 ( V_61 ) ;
V_26 . V_40 = F_11 ( V_62 ) ;
if ( V_64 ) {
V_26 . V_37 |= F_14 ( ( T_2 ) ( V_70
| V_71 ) ) ;
if ( V_64 > V_72 )
V_26 . V_37 |= F_14 ( ( T_2 ) V_73 ) ;
V_26 . V_32 = F_14 ( V_64 ) ;
}
if ( ! V_66 ) {
memset ( & V_67 , 0 , sizeof( V_67 ) ) ;
V_67 . V_74 = true ;
V_66 = & V_67 ;
}
V_3 = F_12 ( V_2 , & V_26 , V_63 , V_64 , V_66 ) ;
return V_3 ;
}
void F_15 ( struct V_1 * V_2 ,
struct V_75 * V_63 )
{
struct V_76 * V_77 ;
int V_34 ;
V_77 = & V_63 -> V_77 [ 0 ] ;
V_2 -> V_78 . V_79 = V_63 -> V_79 ;
V_2 -> V_78 . V_80 = V_63 -> V_81 ;
V_2 -> V_78 . V_82 = V_63 -> V_81 ;
V_2 -> V_78 . V_83 = V_63 -> V_84 ;
V_2 -> V_78 . V_85 = V_63 -> V_86 &
V_87 ;
V_2 -> V_78 . V_88 = ( V_63 -> V_86 &
V_89 ) ? 1 : 0 ;
for ( V_34 = 0 ; V_34 < V_63 -> V_79 ; V_34 ++ ) {
if ( V_77 -> V_90 == V_91 ) {
memcpy ( V_2 -> V_17 . V_92 , V_77 -> V_93 ,
V_94 ) ;
memcpy ( V_2 -> V_17 . V_95 , V_77 -> V_93 ,
V_94 ) ;
}
V_77 ++ ;
}
}
T_1 F_16 ( struct V_1 * V_2 )
{
return F_13 ( V_2 , V_96 ,
0 , NULL , 0 , NULL ) ;
}
