int F_1 ( struct V_1 * V_1 ,
struct V_2 * V_3 )
{
struct V_4 * V_5 ;
struct V_6 * V_7 ;
struct V_8 * V_9 ;
struct V_10 * V_11 ;
struct V_10 * V_12 = NULL ;
struct V_10 * V_13 = NULL ;
long V_14 = V_15 ;
int V_16 ;
int V_17 ;
int V_18 ;
V_11 = V_1 -> V_19 ;
if ( F_2 ( ! V_11 || ! V_11 -> V_5 ) )
return - V_20 ;
V_5 = V_11 -> V_5 ;
F_3 ( & V_5 -> V_21 -> V_5 , L_1 ) ;
V_7 = F_4 ( sizeof( struct V_6 ) , V_22 ) ;
if ( ! V_7 ) {
V_18 = - V_23 ;
goto V_24;
}
F_5 ( & V_7 -> V_25 ) ;
V_7 -> V_26 = V_27 ;
if ( V_5 -> V_28 != V_29 ) {
V_18 = - V_20 ;
goto V_24;
}
if ( V_11 -> V_30 != V_31 &&
V_11 -> V_30 != V_32 ) {
V_18 = - V_33 ;
goto V_24;
}
V_16 = F_6 ( V_5 , V_3 -> V_34 ) ;
if ( V_16 >= 0 && ! V_5 -> V_35 [ V_16 ] . V_36 . V_37 ) {
V_11 -> V_38 = V_5 -> V_35 [ V_16 ] . V_39 ;
V_11 -> V_30 = V_40 ;
}
F_3 ( & V_5 -> V_21 -> V_5 , L_2 ,
V_11 -> V_38 ) ;
F_3 ( & V_5 -> V_21 -> V_5 , L_3 ,
V_5 -> V_35 [ V_16 ] . V_36 . V_41 ) ;
F_3 ( & V_5 -> V_21 -> V_5 , L_4 ,
V_5 -> V_35 [ V_16 ] . V_36 . V_42 ) ;
if ( F_7 ( V_3 -> V_34 , V_43 ) == 0 ) {
F_3 ( & V_5 -> V_21 -> V_5 , L_5 ) ;
if ( V_5 -> V_44 . V_30 != V_45 ) {
V_18 = - V_20 ;
goto V_24;
}
F_8 ( V_11 -> V_46 , V_5 -> V_47 ) ;
F_9 (cl_pos, cl_next,
&dev->file_list, link) {
if ( F_10 ( V_11 , V_12 ) ) {
F_3 ( & V_5 -> V_21 -> V_5 ,
L_6
L_7 ,
V_12 -> V_46 ,
V_12 -> V_38 ) ;
F_11 ( & V_12 -> V_48 ) ;
}
}
F_3 ( & V_5 -> V_21 -> V_5 , L_8 ) ;
F_12 ( V_11 ) ;
V_11 = NULL ;
V_1 -> V_19 = & V_5 -> V_44 ;
V_9 = & V_3 -> V_49 ;
V_9 -> V_42 =
V_5 -> V_35 [ V_16 ] . V_36 . V_42 ;
V_9 -> V_41 =
V_5 -> V_35 [ V_16 ] . V_36 . V_41 ;
V_18 = V_5 -> V_44 . V_50 ;
goto V_24;
}
if ( V_11 -> V_30 != V_40 ) {
V_18 = - V_20 ;
goto V_24;
}
V_9 = & V_3 -> V_49 ;
V_9 -> V_42 = V_5 -> V_35 [ V_16 ] . V_36 . V_42 ;
V_9 -> V_41 = V_5 -> V_35 [ V_16 ] . V_36 . V_41 ;
F_3 ( & V_5 -> V_21 -> V_5 , L_9 ) ;
if ( V_5 -> V_51
&& ! F_13 ( V_5 , V_11 ) ) {
F_3 ( & V_5 -> V_21 -> V_5 , L_10 ) ;
V_5 -> V_51 = false ;
if ( ! F_14 ( V_5 , V_11 ) ) {
F_3 ( & V_5 -> V_21 -> V_5 , L_11 ) ;
V_18 = - V_20 ;
goto V_24;
} else {
F_3 ( & V_5 -> V_21 -> V_5 , L_12 ) ;
V_11 -> V_52 = V_53 ;
V_7 -> V_54 = V_11 ;
F_15 ( & V_7 -> V_25 ,
& V_5 -> V_55 . V_56 .
V_25 ) ;
}
} else {
F_3 ( & V_5 -> V_21 -> V_5 , L_13 ) ;
V_7 -> V_54 = V_11 ;
F_3 ( & V_5 -> V_21 -> V_5 , L_14 ) ;
F_15 ( & V_7 -> V_25 ,
& V_5 -> V_57 . V_56 . V_25 ) ;
}
F_16 ( & V_5 -> V_58 ) ;
V_17 = F_17 ( V_5 -> V_59 ,
( V_45 == V_11 -> V_30 ||
V_32 == V_11 -> V_30 ) ,
V_14 * V_60 ) ;
F_18 ( & V_5 -> V_58 ) ;
if ( V_45 == V_11 -> V_30 ) {
F_3 ( & V_5 -> V_21 -> V_5 , L_15 ) ;
V_18 = V_11 -> V_50 ;
goto V_24;
} else {
F_3 ( & V_5 -> V_21 -> V_5 , L_16 ,
V_11 -> V_30 ) ;
if ( ! V_17 ) {
F_3 ( & V_5 -> V_21 -> V_5 ,
L_17
L_18 ) ;
}
V_18 = - V_61 ;
F_19 ( & V_5 -> V_55 , V_11 ) ;
F_19 ( & V_5 -> V_57 , V_11 ) ;
goto V_24;
}
V_18 = 0 ;
V_24:
F_3 ( & V_5 -> V_21 -> V_5 , L_19 ) ;
F_12 ( V_7 ) ;
return V_18 ;
}
struct V_6 * F_20 (
struct V_4 * V_5 ,
struct V_1 * V_1 )
{
struct V_10 * V_62 ;
struct V_6 * V_63 = NULL ;
struct V_6 * V_64 = NULL ;
if ( ! V_5 -> V_65 . V_50 &&
! F_21 ( & V_5 -> V_65 . V_56 . V_25 ) ) {
F_9 (cb_pos, cb_next,
&dev->amthi_read_complete_list.mei_cb.cb_list, cb_list) {
V_62 = (struct V_10 * ) V_63 -> V_54 ;
if ( V_62 && V_62 == & V_5 -> V_44 &&
V_63 -> V_66 == V_1 )
return V_63 ;
}
}
return NULL ;
}
int F_22 ( struct V_4 * V_5 , struct V_1 * V_1 ,
char T_1 * V_67 , T_2 V_68 , T_3 * V_69 )
{
int V_18 ;
int V_70 ;
struct V_6 * V_7 = NULL ;
struct V_10 * V_11 = V_1 -> V_19 ;
unsigned long V_14 ;
int V_16 ;
if ( ! V_11 || V_11 != & V_5 -> V_44 ) {
F_3 ( & V_5 -> V_21 -> V_5 , L_20 ) ;
return - V_71 ;
}
for ( V_16 = 0 ; V_16 < V_5 -> V_72 ; V_16 ++ ) {
if ( V_5 -> V_35 [ V_16 ] . V_39 ==
V_5 -> V_44 . V_38 )
break;
}
if ( V_16 == V_5 -> V_72 ) {
F_3 ( & V_5 -> V_21 -> V_5 , L_21 ) ;
return - V_20 ;
}
if ( F_2 ( V_5 -> V_35 [ V_16 ] . V_39 != V_11 -> V_38 ) )
return - V_20 ;
F_3 ( & V_5 -> V_21 -> V_5 , L_22 ) ;
V_7 = F_20 ( V_5 , V_1 ) ;
if ( V_7 == NULL && V_1 -> V_73 & V_74 )
return - V_75 ;
F_3 ( & V_5 -> V_21 -> V_5 , L_23 ) ;
while ( V_7 == NULL ) {
F_16 ( & V_5 -> V_58 ) ;
V_70 = F_23 ( V_5 -> V_44 . V_76 ,
( V_7 = F_20 ( V_5 , V_1 ) ) ) ;
if ( V_70 )
return - V_77 ;
F_3 ( & V_5 -> V_21 -> V_5 , L_24 ) ;
F_18 ( & V_5 -> V_58 ) ;
}
F_3 ( & V_5 -> V_21 -> V_5 , L_25 ) ;
V_5 -> V_78 = 0 ;
if ( V_7 ) {
V_14 = V_7 -> V_79 +
F_24 ( V_80 ) ;
F_3 ( & V_5 -> V_21 -> V_5 , L_26 ,
V_14 ) ;
if ( F_25 ( V_81 , V_14 ) ) {
F_3 ( & V_5 -> V_21 -> V_5 , L_27 ) ;
F_11 ( & V_7 -> V_25 ) ;
V_18 = - V_71 ;
goto free;
}
}
if ( V_7 -> V_82 >= * V_69 &&
V_68 >= ( V_7 -> V_82 - * V_69 ) )
F_11 ( & V_7 -> V_25 ) ;
else if ( V_7 -> V_82 > 0 && V_7 -> V_82 <= * V_69 ) {
F_11 ( & V_7 -> V_25 ) ;
V_18 = 0 ;
goto free;
}
F_3 ( & V_5 -> V_21 -> V_5 , L_28 ,
V_7 -> V_83 . V_84 ) ;
F_3 ( & V_5 -> V_21 -> V_5 , L_29 ,
V_7 -> V_82 ) ;
V_68 = F_26 ( T_2 , V_68 , ( V_7 -> V_82 - * V_69 ) ) ;
if ( F_27 ( V_67 ,
V_7 -> V_83 . V_3 + * V_69 ,
V_68 ) )
V_18 = - V_61 ;
else {
V_18 = V_68 ;
if ( ( * V_69 + V_68 ) < V_7 -> V_82 ) {
* V_69 += V_68 ;
goto V_85;
}
}
free:
F_3 ( & V_5 -> V_21 -> V_5 , L_30 ) ;
* V_69 = 0 ;
F_28 ( V_7 ) ;
V_85:
return V_18 ;
}
int F_29 ( struct V_4 * V_5 , struct V_10 * V_11 )
{
struct V_6 * V_7 ;
int V_18 = 0 ;
int V_16 ;
if ( V_11 -> V_30 != V_45 )
return - V_20 ;
if ( V_5 -> V_28 != V_29 )
return - V_20 ;
F_3 ( & V_5 -> V_21 -> V_5 , L_31 ) ;
if ( V_11 -> V_86 || V_11 -> V_87 ) {
F_3 ( & V_5 -> V_21 -> V_5 , L_32 ) ;
return - V_33 ;
}
V_7 = F_4 ( sizeof( struct V_6 ) , V_22 ) ;
if ( ! V_7 )
return - V_23 ;
F_3 ( & V_5 -> V_21 -> V_5 , L_33 ,
V_11 -> V_46 , V_11 -> V_38 ) ;
for ( V_16 = 0 ; V_16 < V_5 -> V_72 ; V_16 ++ ) {
if ( V_5 -> V_35 [ V_16 ] . V_39 == V_11 -> V_38 )
break;
}
if ( F_2 ( V_5 -> V_35 [ V_16 ] . V_39 != V_11 -> V_38 ) ) {
V_18 = - V_20 ;
goto V_88;
}
if ( V_16 == V_5 -> V_72 ) {
V_18 = - V_20 ;
goto V_88;
}
V_7 -> V_83 . V_84 = V_5 -> V_35 [ V_16 ] . V_36 . V_42 ;
V_7 -> V_83 . V_3 =
F_30 ( V_7 -> V_83 . V_84 , V_22 ) ;
if ( ! V_7 -> V_83 . V_3 ) {
V_18 = - V_23 ;
goto V_88;
}
F_3 ( & V_5 -> V_21 -> V_5 , L_34 ) ;
V_7 -> V_26 = V_89 ;
V_7 -> V_82 = 0 ;
V_7 -> V_54 = ( void * ) V_11 ;
V_11 -> V_87 = V_7 ;
if ( V_5 -> V_51 ) {
V_5 -> V_51 = false ;
if ( ! F_31 ( V_5 , V_11 ) ) {
V_18 = - V_20 ;
goto V_88;
} else {
F_15 ( & V_7 -> V_25 ,
& V_5 -> V_90 . V_56 . V_25 ) ;
}
} else {
F_15 ( & V_7 -> V_25 ,
& V_5 -> V_57 . V_56 . V_25 ) ;
}
return V_18 ;
V_88:
F_28 ( V_7 ) ;
return V_18 ;
}
int F_32 ( struct V_4 * V_5 , struct V_6 * V_7 )
{
struct V_91 V_92 ;
int V_93 ;
if ( ! V_5 || ! V_7 )
return - V_20 ;
F_3 ( & V_5 -> V_21 -> V_5 , L_35 ) ;
V_5 -> V_94 = V_95 ;
V_5 -> V_96 = V_7 ;
V_5 -> V_97 = V_7 -> V_66 ;
V_5 -> V_98 = false ;
V_5 -> V_99 = true ;
V_5 -> V_100 = V_7 -> V_101 . V_84 ;
memcpy ( V_5 -> V_102 , V_7 -> V_101 . V_3 ,
V_7 -> V_101 . V_84 ) ;
V_93 = F_33 ( V_5 , & V_5 -> V_44 ) ;
if ( V_93 < 0 )
return V_93 ;
if ( V_93 && V_5 -> V_51 ) {
V_93 = 0 ;
V_5 -> V_51 = false ;
if ( V_7 -> V_101 . V_84 >
( ( ( V_5 -> V_103 & V_104 ) >> 24 ) * sizeof( V_105 ) )
- sizeof( struct V_91 ) ) {
V_92 . V_68 =
( ( ( V_5 -> V_103 & V_104 ) >> 24 ) *
sizeof( V_105 ) ) - sizeof( struct V_91 ) ;
V_92 . V_106 = 0 ;
} else {
V_92 . V_68 = V_7 -> V_101 . V_84 ;
V_92 . V_106 = 1 ;
}
V_92 . V_107 = V_5 -> V_44 . V_46 ;
V_92 . V_108 = V_5 -> V_44 . V_38 ;
V_92 . V_109 = 0 ;
V_5 -> V_110 += V_92 . V_68 ;
if ( ! F_34 ( V_5 , & V_92 ,
( unsigned char * ) ( V_5 -> V_102 ) ,
V_92 . V_68 ) )
return - V_20 ;
if ( V_92 . V_106 ) {
if ( F_35 ( V_5 , & V_5 -> V_44 ) )
return - V_20 ;
V_5 -> V_111 = true ;
V_5 -> V_94 = V_112 ;
F_3 ( & V_5 -> V_21 -> V_5 , L_36 ) ;
V_5 -> V_96 = V_7 ;
V_5 -> V_97 = V_7 -> V_66 ;
F_15 ( & V_7 -> V_25 ,
& V_5 -> V_113 . V_56 . V_25 ) ;
} else {
F_3 ( & V_5 -> V_21 -> V_5 , L_37
L_38 ) ;
F_15 ( & V_7 -> V_25 ,
& V_5 -> V_114 . V_56 . V_25 ) ;
}
} else {
if ( ! ( V_5 -> V_51 ) )
F_3 ( & V_5 -> V_21 -> V_5 , L_39 ) ;
F_3 ( & V_5 -> V_21 -> V_5 , L_40
L_41 ) ;
F_15 ( & V_7 -> V_25 ,
& V_5 -> V_114 . V_56 . V_25 ) ;
}
return 0 ;
}
void F_36 ( struct V_4 * V_5 )
{
struct V_10 * V_115 ;
struct V_6 * V_63 = NULL ;
struct V_6 * V_64 = NULL ;
int V_50 ;
if ( ! V_5 )
return;
V_5 -> V_100 = 0 ;
V_5 -> V_110 = 0 ;
V_5 -> V_98 = false ;
V_5 -> V_99 = true ;
V_5 -> V_94 = V_116 ;
V_5 -> V_78 = 0 ;
V_5 -> V_97 = NULL ;
if ( V_5 -> V_117 . V_50 == 0 &&
! F_21 ( & V_5 -> V_117 . V_56 . V_25 ) ) {
F_3 ( & V_5 -> V_21 -> V_5 , L_42 ) ;
F_9 (cb_pos, cb_next,
&dev->amthi_cmd_list.mei_cb.cb_list, cb_list) {
F_11 ( & V_63 -> V_25 ) ;
V_115 = (struct V_10 * ) V_63 -> V_54 ;
if ( V_115 && V_115 == & V_5 -> V_44 ) {
V_50 = F_32 ( V_5 , V_63 ) ;
if ( V_50 ) {
F_3 ( & V_5 -> V_21 -> V_5 ,
L_43 ,
V_50 ) ;
return;
}
break;
}
}
}
}
void F_28 ( struct V_6 * V_7 )
{
if ( V_7 == NULL )
return;
F_12 ( V_7 -> V_101 . V_3 ) ;
F_12 ( V_7 -> V_83 . V_3 ) ;
F_12 ( V_7 ) ;
}
