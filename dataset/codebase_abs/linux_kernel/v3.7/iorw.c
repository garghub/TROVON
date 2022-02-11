int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_5 ; V_4 ++ )
if ( V_2 -> V_6 [ V_4 ] . V_3 == V_3 )
break;
if ( F_2 ( V_2 -> V_6 [ V_4 ] . V_3 != V_3 ) )
return - V_7 ;
if ( V_4 == V_2 -> V_5 )
return - V_7 ;
return V_4 ;
}
int F_3 ( struct V_8 * V_8 ,
struct V_9 * V_10 )
{
struct V_1 * V_2 ;
struct V_11 * V_12 ;
struct V_13 * V_14 ;
struct V_15 * V_16 ;
struct V_15 * V_17 = NULL ;
struct V_15 * V_18 = NULL ;
long V_19 = V_20 ;
int V_4 ;
int V_21 ;
int V_22 ;
V_16 = V_8 -> V_23 ;
if ( F_2 ( ! V_16 || ! V_16 -> V_2 ) )
return - V_24 ;
V_2 = V_16 -> V_2 ;
F_4 ( & V_2 -> V_25 -> V_2 , L_1 ) ;
V_12 = F_5 ( sizeof( struct V_11 ) , V_26 ) ;
if ( ! V_12 ) {
V_22 = - V_27 ;
goto V_28;
}
F_6 ( & V_12 -> V_29 ) ;
V_12 -> V_30 = V_31 ;
if ( V_2 -> V_32 != V_33 ) {
V_22 = - V_24 ;
goto V_28;
}
if ( V_16 -> V_34 != V_35 &&
V_16 -> V_34 != V_36 ) {
V_22 = - V_37 ;
goto V_28;
}
V_4 = F_7 ( V_2 , & V_10 -> V_38 ) ;
if ( V_4 >= 0 && ! V_2 -> V_6 [ V_4 ] . V_39 . V_40 ) {
V_16 -> V_41 = V_2 -> V_6 [ V_4 ] . V_3 ;
V_16 -> V_34 = V_42 ;
}
F_4 ( & V_2 -> V_25 -> V_2 , L_2 ,
V_16 -> V_41 ) ;
F_4 ( & V_2 -> V_25 -> V_2 , L_3 ,
V_2 -> V_6 [ V_4 ] . V_39 . V_43 ) ;
F_4 ( & V_2 -> V_25 -> V_2 , L_4 ,
V_2 -> V_6 [ V_4 ] . V_39 . V_44 ) ;
if ( F_8 ( V_10 -> V_38 , V_45 ) == 0 ) {
F_4 ( & V_2 -> V_25 -> V_2 , L_5 ) ;
if ( V_2 -> V_46 . V_34 != V_47 ) {
V_22 = - V_24 ;
goto V_28;
}
F_9 ( V_16 -> V_48 , V_2 -> V_49 ) ;
F_10 (cl_pos, cl_next,
&dev->file_list, link) {
if ( F_11 ( V_16 , V_17 ) ) {
F_4 ( & V_2 -> V_25 -> V_2 ,
L_6
L_7 ,
V_17 -> V_48 ,
V_17 -> V_41 ) ;
F_12 ( & V_17 -> V_50 ) ;
}
}
F_4 ( & V_2 -> V_25 -> V_2 , L_8 ) ;
F_13 ( V_16 ) ;
V_16 = NULL ;
V_8 -> V_23 = & V_2 -> V_46 ;
V_14 = & V_10 -> V_51 ;
V_14 -> V_44 =
V_2 -> V_6 [ V_4 ] . V_39 . V_44 ;
V_14 -> V_43 =
V_2 -> V_6 [ V_4 ] . V_39 . V_43 ;
V_22 = V_2 -> V_46 . V_52 ;
goto V_28;
}
if ( V_16 -> V_34 != V_42 ) {
V_22 = - V_24 ;
goto V_28;
}
V_14 = & V_10 -> V_51 ;
V_14 -> V_44 = V_2 -> V_6 [ V_4 ] . V_39 . V_44 ;
V_14 -> V_43 = V_2 -> V_6 [ V_4 ] . V_39 . V_43 ;
F_4 ( & V_2 -> V_25 -> V_2 , L_9 ) ;
if ( V_2 -> V_53
&& ! F_14 ( V_2 , V_16 ) ) {
F_4 ( & V_2 -> V_25 -> V_2 , L_10 ) ;
V_2 -> V_53 = false ;
if ( F_15 ( V_2 , V_16 ) ) {
F_4 ( & V_2 -> V_25 -> V_2 , L_11 ) ;
V_22 = - V_24 ;
goto V_28;
} else {
F_4 ( & V_2 -> V_25 -> V_2 , L_12 ) ;
V_16 -> V_54 = V_55 ;
V_12 -> V_56 = V_16 ;
F_16 ( & V_12 -> V_29 ,
& V_2 -> V_57 . V_58 .
V_29 ) ;
}
} else {
F_4 ( & V_2 -> V_25 -> V_2 , L_13 ) ;
V_12 -> V_56 = V_16 ;
F_4 ( & V_2 -> V_25 -> V_2 , L_14 ) ;
F_16 ( & V_12 -> V_29 ,
& V_2 -> V_59 . V_58 . V_29 ) ;
}
F_17 ( & V_2 -> V_60 ) ;
V_21 = F_18 ( V_2 -> V_61 ,
( V_47 == V_16 -> V_34 ||
V_36 == V_16 -> V_34 ) ,
V_19 * V_62 ) ;
F_19 ( & V_2 -> V_60 ) ;
if ( V_47 == V_16 -> V_34 ) {
F_4 ( & V_2 -> V_25 -> V_2 , L_15 ) ;
V_22 = V_16 -> V_52 ;
goto V_28;
} else {
F_4 ( & V_2 -> V_25 -> V_2 , L_16 ,
V_16 -> V_34 ) ;
if ( ! V_21 ) {
F_4 ( & V_2 -> V_25 -> V_2 ,
L_17
L_18 ) ;
}
V_22 = - V_63 ;
F_20 ( & V_2 -> V_57 , V_16 ) ;
F_20 ( & V_2 -> V_59 , V_16 ) ;
goto V_28;
}
V_22 = 0 ;
V_28:
F_4 ( & V_2 -> V_25 -> V_2 , L_19 ) ;
F_13 ( V_12 ) ;
return V_22 ;
}
struct V_11 * F_21 (
struct V_1 * V_2 ,
struct V_8 * V_8 )
{
struct V_15 * V_64 ;
struct V_11 * V_65 = NULL ;
struct V_11 * V_66 = NULL ;
F_10 (pos, next,
&dev->amthi_read_complete_list.mei_cb.cb_list, cb_list) {
V_64 = (struct V_15 * ) V_65 -> V_56 ;
if ( V_64 && V_64 == & V_2 -> V_46 &&
V_65 -> V_67 == V_8 )
return V_65 ;
}
return NULL ;
}
int F_22 ( struct V_1 * V_2 , struct V_8 * V_8 ,
char T_2 * V_68 , T_3 V_69 , T_4 * V_70 )
{
int V_22 ;
int V_71 ;
struct V_11 * V_12 = NULL ;
struct V_15 * V_16 = V_8 -> V_23 ;
unsigned long V_19 ;
int V_4 ;
if ( ! V_16 || V_16 != & V_2 -> V_46 ) {
F_4 ( & V_2 -> V_25 -> V_2 , L_20 ) ;
return - V_72 ;
}
V_4 = F_1 ( V_2 , V_2 -> V_46 . V_41 ) ;
if ( V_4 < 0 ) {
F_4 ( & V_2 -> V_25 -> V_2 , L_21 ) ;
return - V_24 ;
}
F_4 ( & V_2 -> V_25 -> V_2 , L_22 ) ;
V_12 = F_21 ( V_2 , V_8 ) ;
if ( V_12 == NULL && V_8 -> V_73 & V_74 )
return - V_75 ;
F_4 ( & V_2 -> V_25 -> V_2 , L_23 ) ;
while ( V_12 == NULL ) {
F_17 ( & V_2 -> V_60 ) ;
V_71 = F_23 ( V_2 -> V_46 . V_76 ,
( V_12 = F_21 ( V_2 , V_8 ) ) ) ;
if ( V_71 )
return - V_77 ;
F_4 ( & V_2 -> V_25 -> V_2 , L_24 ) ;
F_19 ( & V_2 -> V_60 ) ;
}
F_4 ( & V_2 -> V_25 -> V_2 , L_25 ) ;
V_2 -> V_78 = 0 ;
if ( V_12 ) {
V_19 = V_12 -> V_79 + F_24 ( V_80 ) ;
F_4 ( & V_2 -> V_25 -> V_2 , L_26 ,
V_19 ) ;
if ( F_25 ( V_81 , V_19 ) ) {
F_4 ( & V_2 -> V_25 -> V_2 , L_27 ) ;
F_12 ( & V_12 -> V_29 ) ;
V_22 = - V_72 ;
goto free;
}
}
if ( V_12 -> V_82 >= * V_70 && V_69 >= ( V_12 -> V_82 - * V_70 ) )
F_12 ( & V_12 -> V_29 ) ;
else if ( V_12 -> V_82 > 0 && V_12 -> V_82 <= * V_70 ) {
F_12 ( & V_12 -> V_29 ) ;
V_22 = 0 ;
goto free;
}
F_4 ( & V_2 -> V_25 -> V_2 , L_28 ,
V_12 -> V_83 . V_84 ) ;
F_4 ( & V_2 -> V_25 -> V_2 , L_29 ,
V_12 -> V_82 ) ;
V_69 = F_26 ( T_3 , V_69 , ( V_12 -> V_82 - * V_70 ) ) ;
if ( F_27 ( V_68 , V_12 -> V_83 . V_10 + * V_70 , V_69 ) )
V_22 = - V_63 ;
else {
V_22 = V_69 ;
if ( ( * V_70 + V_69 ) < V_12 -> V_82 ) {
* V_70 += V_69 ;
goto V_85;
}
}
free:
F_4 ( & V_2 -> V_25 -> V_2 , L_30 ) ;
* V_70 = 0 ;
F_28 ( V_12 ) ;
V_85:
return V_22 ;
}
int F_29 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
struct V_11 * V_12 ;
int V_22 = 0 ;
int V_4 ;
if ( V_16 -> V_34 != V_47 )
return - V_24 ;
if ( V_2 -> V_32 != V_33 )
return - V_24 ;
F_4 ( & V_2 -> V_25 -> V_2 , L_31 ) ;
if ( V_16 -> V_86 || V_16 -> V_87 ) {
F_4 ( & V_2 -> V_25 -> V_2 , L_32 ) ;
return - V_37 ;
}
V_12 = F_5 ( sizeof( struct V_11 ) , V_26 ) ;
if ( ! V_12 )
return - V_27 ;
F_4 ( & V_2 -> V_25 -> V_2 , L_33 ,
V_16 -> V_48 , V_16 -> V_41 ) ;
V_4 = F_1 ( V_2 , V_16 -> V_41 ) ;
if ( V_4 < 0 ) {
V_22 = - V_24 ;
goto V_88;
}
V_12 -> V_83 . V_84 = V_2 -> V_6 [ V_4 ] . V_39 . V_44 ;
V_12 -> V_83 . V_10 =
F_30 ( V_12 -> V_83 . V_84 , V_26 ) ;
if ( ! V_12 -> V_83 . V_10 ) {
V_22 = - V_27 ;
goto V_88;
}
F_4 ( & V_2 -> V_25 -> V_2 , L_34 ) ;
V_12 -> V_30 = V_89 ;
V_12 -> V_82 = 0 ;
V_12 -> V_56 = ( void * ) V_16 ;
V_16 -> V_87 = V_12 ;
if ( V_2 -> V_53 ) {
V_2 -> V_53 = false ;
if ( F_31 ( V_2 , V_16 ) ) {
V_22 = - V_24 ;
goto V_88;
}
F_16 ( & V_12 -> V_29 , & V_2 -> V_90 . V_58 . V_29 ) ;
} else {
F_16 ( & V_12 -> V_29 , & V_2 -> V_59 . V_58 . V_29 ) ;
}
return V_22 ;
V_88:
F_28 ( V_12 ) ;
return V_22 ;
}
int F_32 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
struct V_91 V_92 ;
int V_93 ;
if ( ! V_2 || ! V_12 )
return - V_24 ;
F_4 ( & V_2 -> V_25 -> V_2 , L_35 ) ;
V_2 -> V_94 = V_95 ;
V_2 -> V_96 = V_12 ;
V_2 -> V_97 = V_12 -> V_67 ;
V_2 -> V_98 = false ;
V_2 -> V_99 = true ;
V_2 -> V_100 = V_12 -> V_101 . V_84 ;
memcpy ( V_2 -> V_102 , V_12 -> V_101 . V_10 ,
V_12 -> V_101 . V_84 ) ;
V_93 = F_33 ( V_2 , & V_2 -> V_46 ) ;
if ( V_93 < 0 )
return V_93 ;
if ( V_93 && V_2 -> V_53 ) {
V_93 = 0 ;
V_2 -> V_53 = false ;
if ( V_12 -> V_101 . V_84 > F_34 ( V_2 ) ) {
V_92 . V_69 = F_34 ( V_2 ) ;
V_92 . V_103 = 0 ;
} else {
V_92 . V_69 = V_12 -> V_101 . V_84 ;
V_92 . V_103 = 1 ;
}
V_92 . V_104 = V_2 -> V_46 . V_48 ;
V_92 . V_105 = V_2 -> V_46 . V_41 ;
V_92 . V_106 = 0 ;
V_2 -> V_107 += V_92 . V_69 ;
if ( F_35 ( V_2 , & V_92 ,
( unsigned char * ) ( V_2 -> V_102 ) ,
V_92 . V_69 ) )
return - V_24 ;
if ( V_92 . V_103 ) {
if ( F_36 ( V_2 , & V_2 -> V_46 ) )
return - V_24 ;
V_2 -> V_108 = true ;
V_2 -> V_94 = V_109 ;
F_4 ( & V_2 -> V_25 -> V_2 , L_36 ) ;
V_2 -> V_96 = V_12 ;
V_2 -> V_97 = V_12 -> V_67 ;
F_16 ( & V_12 -> V_29 ,
& V_2 -> V_110 . V_58 . V_29 ) ;
} else {
F_4 ( & V_2 -> V_25 -> V_2 , L_37
L_38 ) ;
F_16 ( & V_12 -> V_29 ,
& V_2 -> V_111 . V_58 . V_29 ) ;
}
} else {
if ( ! ( V_2 -> V_53 ) )
F_4 ( & V_2 -> V_25 -> V_2 , L_39 ) ;
F_4 ( & V_2 -> V_25 -> V_2 , L_40
L_41 ) ;
F_16 ( & V_12 -> V_29 , & V_2 -> V_111 . V_58 . V_29 ) ;
}
return 0 ;
}
void F_37 ( struct V_1 * V_2 )
{
struct V_15 * V_112 ;
struct V_11 * V_65 = NULL ;
struct V_11 * V_66 = NULL ;
int V_52 ;
if ( ! V_2 )
return;
V_2 -> V_100 = 0 ;
V_2 -> V_107 = 0 ;
V_2 -> V_98 = false ;
V_2 -> V_99 = true ;
V_2 -> V_94 = V_113 ;
V_2 -> V_78 = 0 ;
V_2 -> V_97 = NULL ;
F_4 ( & V_2 -> V_25 -> V_2 , L_42 ) ;
F_10 (pos, next,
&dev->amthi_cmd_list.mei_cb.cb_list, cb_list) {
F_12 ( & V_65 -> V_29 ) ;
V_112 = (struct V_15 * ) V_65 -> V_56 ;
if ( V_112 && V_112 == & V_2 -> V_46 ) {
V_52 = F_32 ( V_2 , V_65 ) ;
if ( V_52 ) {
F_4 ( & V_2 -> V_25 -> V_2 ,
L_43 ,
V_52 ) ;
return;
}
break;
}
}
}
void F_28 ( struct V_11 * V_12 )
{
if ( V_12 == NULL )
return;
F_13 ( V_12 -> V_101 . V_10 ) ;
F_13 ( V_12 -> V_83 . V_10 ) ;
F_13 ( V_12 ) ;
}
