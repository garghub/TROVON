void F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
struct V_5 V_6 ;
F_2 ( & V_6 , & V_4 -> V_7 ) ;
F_3 ( V_1 , L_1 V_8 L_2 ,
F_4 ( & V_6 ) , F_5 ( V_4 -> V_9 ) ,
F_5 ( V_4 -> V_10 ) ) ;
F_3 ( V_1 , L_3 ,
F_5 ( V_4 -> V_11 ) ,
F_6 ( V_4 -> V_12 ) ,
F_6 ( V_4 -> V_13 ) ) ;
}
static void F_7 ( int V_1 , struct V_14 * V_15 ,
int V_16 )
{
int V_17 ;
if ( V_16 > V_18 ) {
F_3 ( V_1 , L_4 ,
V_16 , V_18 ) ;
return;
}
for ( V_17 = 0 ; V_17 < V_16 ; ++ V_17 , ++ V_15 ) {
struct V_5 V_6 ;
F_8 ( & V_15 -> V_19 , & V_6 ) ;
F_3 ( V_1 , L_5 V_8 L_6 , V_17 ,
F_5 ( V_15 -> V_20 ) , F_4 ( & V_6 ) ) ;
}
}
void F_9 ( int V_1 , struct V_21 * V_4 )
{
F_1 ( V_1 , V_4 ) ;
F_7 ( V_1 , V_4 -> V_22 ,
F_6 ( V_4 -> V_12 ) ) ;
}
void F_10 ( int V_1 , struct V_23 * V_4 )
{
F_1 ( V_1 , V_4 ) ;
F_3 ( V_1 , L_7 V_24 L_6 , V_4 -> V_25 ) ;
F_7 ( V_1 , V_4 -> V_22 ,
F_6 ( V_4 -> V_12 ) ) ;
}
int F_11 ( struct V_26 * V_27 , struct V_3 * * V_2 ,
struct V_28 * V_29 )
{
struct V_21 * V_30 ;
struct V_23 * V_31 ;
T_1 V_16 ;
struct V_32 * V_22 ;
int V_33 , V_9 ;
int V_17 ;
int V_34 = 0 ;
if ( V_29 ) {
V_9 = V_29 -> V_35 ;
} else {
if ( V_2 && * V_2 )
V_9 = F_5 ( ( * V_2 ) -> V_9 ) ;
else
V_9 = V_36 ;
}
if ( ( V_9 != V_37 ) &&
( V_9 != V_38 ) ) {
F_12 ( L_8 ,
V_9 , V_37 , V_38 ) ;
return - V_39 ;
}
if ( V_29 ) {
if ( ! V_2 ) {
V_16 = F_13 ( V_27 , V_9 ,
V_29 -> V_40 ) ;
V_29 -> V_40 = V_16 ;
} else if ( ! F_14 ( V_29 ) ) {
V_16 = V_29 -> V_40 ;
} else {
V_16 = 0 ;
}
} else {
V_16 = V_27 -> V_41 . V_42 ;
}
V_33 = F_15 ( V_16 , V_9 ) ;
if ( ! V_2 )
return V_33 ;
if ( * V_2 && ! V_29 ) {
V_16 = F_6 ( ( * V_2 ) -> V_12 ) ;
V_33 = F_15 ( V_16 , V_9 ) ;
F_16 ( * V_2 ) ;
* V_2 = NULL ;
return 0 ;
}
if ( ! * V_2 ) {
* V_2 = F_17 ( V_33 , V_43 ) ;
if ( ! * V_2 )
return - V_44 ;
}
F_3 ( V_45 , L_9 ,
V_9 , V_33 ) ;
V_30 = * V_2 ;
V_31 = (struct V_23 * ) * V_2 ;
if ( V_9 == V_38 )
V_31 -> V_9 = F_18 ( V_38 ) ;
else
V_30 -> V_9 = F_18 ( V_37 ) ;
if ( ! V_29 )
return V_33 ;
F_19 ( & V_30 -> V_7 , & V_29 -> V_46 ) ;
V_30 -> V_11 = F_18 ( V_29 -> V_47 ) ;
V_30 -> V_12 = F_20 ( V_16 ) ;
V_30 -> V_10 = F_18 ( V_29 -> V_48 ) ;
V_30 -> V_13 = F_20 ( V_29 -> V_49 ) ;
if ( V_29 -> V_35 == V_38 ) {
V_34 = F_21 ( V_31 -> V_25 , V_29 -> V_50 ,
sizeof( V_31 -> V_25 ) ) ;
if ( V_34 >= sizeof( V_31 -> V_25 ) )
return - V_51 ;
V_22 = V_31 -> V_22 ;
} else {
V_22 = V_30 -> V_22 ;
}
for ( V_17 = 0 ; V_17 < V_16 ; V_17 ++ ) {
struct V_52 * V_53 = V_29 -> V_54 [ V_17 ] ;
F_22 ( F_23 ( & V_53 -> V_55 ) != 0 , L_10 V_8
L_11 , F_4 ( & V_30 -> V_7 ) ,
V_17 , V_16 , V_53 -> V_56 ) ;
F_24 ( & V_53 -> V_55 , & V_22 [ V_17 ] . V_19 ) ;
V_22 [ V_17 ] . V_57 = F_18 ( V_53 -> V_58 ) ;
V_22 [ V_17 ] . V_20 = F_18 ( V_53 -> V_56 ) ;
}
return V_33 ;
}
int F_25 ( struct V_59 * exp , struct V_3 * * V_2 ,
struct V_28 * V_29 )
{
struct V_60 * V_61 = F_26 ( exp ) ;
struct V_26 * V_27 = & V_61 -> V_62 . V_27 ;
return F_11 ( V_27 , V_2 , V_29 ) ;
}
T_1 F_13 ( struct V_26 * V_27 , T_2 V_63 , T_1 V_16 )
{
T_2 V_64 = V_65 ;
if ( ! V_16 )
V_16 = V_27 -> V_41 . V_66 ;
if ( V_16 > V_27 -> V_41 . V_42 )
V_16 = V_27 -> V_41 . V_42 ;
if ( ! V_16 )
V_16 = 1 ;
if ( V_27 -> V_67 . V_68 & V_69 &&
V_27 -> V_67 . V_70 )
V_64 = F_27 (
V_27 -> V_67 . V_70 , V_63 ) ;
if ( V_16 > V_64 )
V_16 = V_64 ;
return V_16 ;
}
static int F_28 ( void * V_4 , int V_71 , T_1 * V_16 )
{
int V_72 ;
if ( ! F_29 ( F_5 ( * ( T_2 * ) V_4 ) ) ) {
F_12 ( L_12 ,
F_5 ( * ( T_2 * ) V_4 ) , V_71 ) ;
F_12 ( L_13 , V_71 , V_4 ) ;
return - V_39 ;
}
V_72 = F_29 ( F_5 ( * ( T_2 * ) V_4 ) ) -> F_30 ( V_4 ,
V_71 ,
V_16 ) ;
return V_72 ;
}
int F_31 ( struct V_28 * * V_73 , T_1 V_16 ,
int V_74 , int V_63 )
{
int V_17 , V_75 ;
F_3 ( V_45 , L_14 , V_16 ) ;
* V_73 = F_32 ( V_16 , & V_75 ) ;
if ( ! * V_73 ) {
F_12 ( L_15 , V_16 ) ;
return - V_44 ;
}
F_33 ( & ( * V_73 ) -> V_76 , 1 ) ;
F_34 ( & ( * V_73 ) -> V_77 ) ;
( * V_73 ) -> V_35 = V_63 ;
( * V_73 ) -> V_40 = V_16 ;
( * V_73 ) -> V_78 = V_79 * V_16 ;
( * V_73 ) -> V_48 = V_74 ;
( * V_73 ) -> V_50 [ 0 ] = '\0' ;
( * V_73 ) -> V_49 = 0 ;
if ( V_16 > 0 )
( * V_73 ) -> V_54 [ 0 ] -> V_56 = ~ 0 ;
for ( V_17 = 0 ; V_17 < V_16 ; V_17 ++ )
F_35 ( ( * V_73 ) -> V_54 [ V_17 ] ) ;
return V_75 ;
}
int F_36 ( struct V_28 * * V_73 )
{
struct V_28 * V_29 = * V_73 ;
int V_80 ;
* V_73 = NULL ;
F_37 ( F_38 ( & V_29 -> V_76 ) > 0 ) ;
V_80 = F_39 ( & V_29 -> V_76 ) ;
if ( V_80 == 0 )
F_29 ( V_29 -> V_35 ) -> F_40 ( V_29 ) ;
return V_80 ;
}
int F_41 ( struct V_59 * exp , struct V_28 * * V_73 ,
struct V_3 * V_4 , int V_71 )
{
struct V_60 * V_61 = F_26 ( exp ) ;
struct V_26 * V_27 = & V_61 -> V_62 . V_27 ;
int V_72 = 0 , V_75 ;
T_1 V_16 ;
T_2 V_63 ;
T_2 V_74 ;
if ( V_4 ) {
V_72 = F_28 ( V_4 , V_71 , & V_16 ) ;
if ( V_72 )
return V_72 ;
V_63 = F_5 ( V_4 -> V_9 ) ;
V_74 = F_5 ( V_4 -> V_10 ) ;
} else {
V_63 = V_36 ;
V_16 = F_13 ( V_27 , V_63 , 0 ) ;
V_74 = V_81 ;
}
if ( ! V_73 ) {
F_42 () ;
return F_43 ( V_16 ) ;
}
if ( * V_73 && ! V_4 ) {
F_36 ( V_73 ) ;
return 0 ;
}
V_75 = F_31 ( V_73 , V_16 , V_74 , V_63 ) ;
if ( V_75 < 0 )
return V_75 ;
if ( ! V_4 )
return V_75 ;
V_72 = F_29 ( V_63 ) -> F_44 ( V_27 , * V_73 , V_4 ) ;
if ( V_72 ) {
F_36 ( V_73 ) ;
return V_72 ;
}
return V_75 ;
}
int F_45 ( struct V_82 * V_83 , struct V_28 * V_29 ,
struct V_84 T_3 * V_85 )
{
struct V_26 * V_27 ;
struct V_86 V_87 ;
struct V_3 * V_88 = NULL ;
int V_72 , V_89 , V_33 ;
int V_90 ;
T_4 V_91 ;
if ( ! V_29 )
return - V_92 ;
V_91 = F_46 () ;
F_47 ( V_93 ) ;
V_90 = sizeof( struct V_94 ) ;
if ( F_48 ( & V_87 , V_85 , V_90 ) ) {
V_72 = - V_95 ;
goto V_96;
}
if ( V_87 . V_9 != V_97 &&
V_87 . V_9 != V_98 &&
V_87 . V_9 != V_99 ) {
V_72 = - V_39 ;
goto V_96;
}
if ( V_87 . V_12 &&
( V_87 . V_12 < V_29 -> V_40 ) ) {
V_87 . V_12 = V_29 -> V_40 ;
V_72 = F_49 ( V_85 , & V_87 , V_90 ) ;
V_72 = - V_100 ;
goto V_96;
}
V_27 = F_50 ( V_83 -> V_101 . V_102 . V_103 ) -> V_104 ;
V_72 = F_11 ( V_27 , & V_88 , V_29 ) ;
if ( V_72 < 0 )
goto V_96;
V_89 = V_72 ;
V_33 = V_72 ;
V_72 = 0 ;
F_51 ( sizeof( V_87 ) == sizeof( struct V_23 ) ) ;
F_51 ( sizeof( V_87 . V_22 [ 0 ] ) == sizeof( V_88 -> V_22 [ 0 ] ) ) ;
if ( ( F_18 ( V_36 ) != V_36 ) &&
( ( V_88 -> V_9 == F_18 ( V_37 ) ) ||
( V_88 -> V_9 == F_18 ( V_38 ) ) ) ) {
F_52 ( V_88 ) ;
F_53 (
(struct V_105 * ) V_88 -> V_22 ,
V_88 -> V_12 ) ;
}
if ( V_87 . V_9 == V_106 ) {
if ( V_88 -> V_9 == V_38 ) {
memmove ( ( (struct V_21 * ) V_88 ) -> V_22 ,
( (struct V_23 * ) V_88 ) -> V_22 ,
V_88 -> V_12 *
sizeof( struct V_32 ) ) ;
V_33 -= V_107 ;
}
} else {
V_90 = sizeof( struct V_86 ) ;
}
if ( V_87 . V_12 == 0 ) {
V_33 = V_90 ;
} else if ( V_87 . V_12 < V_88 -> V_12 ) {
V_72 = - V_100 ;
goto V_108;
}
V_87 . V_12 = V_88 -> V_12 ;
V_87 . V_13 = V_88 -> V_13 ;
( (struct V_84 * ) V_88 ) -> V_13 = V_87 . V_13 ;
( (struct V_84 * ) V_88 ) -> V_12 = V_87 . V_12 ;
if ( F_49 ( V_85 , V_88 , V_33 ) )
V_72 = - V_95 ;
V_108:
F_54 ( V_88 ) ;
V_96:
F_47 ( V_91 ) ;
return V_72 ;
}
