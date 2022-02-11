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
int F_11 ( struct V_26 * exp , struct V_3 * * V_2 ,
struct V_27 * V_28 )
{
struct V_29 * V_30 = F_12 ( exp ) ;
struct V_31 * V_32 = & V_30 -> V_33 . V_32 ;
struct V_21 * V_34 ;
struct V_23 * V_35 ;
T_1 V_16 ;
struct V_36 * V_22 ;
int V_37 , V_9 ;
int V_17 ;
int V_38 = 0 ;
if ( V_28 ) {
V_9 = V_28 -> V_39 ;
} else {
if ( V_2 && * V_2 )
V_9 = F_5 ( ( * V_2 ) -> V_9 ) ;
else
V_9 = V_40 ;
}
if ( ( V_9 != V_41 ) &&
( V_9 != V_42 ) ) {
F_13 ( L_8 ,
V_9 , V_41 , V_42 ) ;
return - V_43 ;
}
if ( V_28 ) {
if ( ! V_2 ) {
V_16 = F_14 ( V_32 , V_9 ,
V_28 -> V_44 ) ;
V_28 -> V_44 = V_16 ;
} else if ( ! F_15 ( V_28 ) ) {
V_16 = V_28 -> V_44 ;
} else {
V_16 = 0 ;
}
} else {
V_16 = F_16 (
V_32 -> V_45 . V_46 , V_9 ) ;
if ( V_16 > V_32 -> V_47 . V_48 )
V_16 = V_32 -> V_47 . V_48 ;
}
V_37 = F_17 ( V_16 , V_9 ) ;
if ( ! V_2 )
return V_37 ;
if ( * V_2 && ! V_28 ) {
V_16 = F_6 ( ( * V_2 ) -> V_12 ) ;
V_37 = F_17 ( V_16 , V_9 ) ;
F_18 ( * V_2 ) ;
* V_2 = NULL ;
return 0 ;
}
if ( ! * V_2 ) {
* V_2 = F_19 ( V_37 , V_49 ) ;
if ( ! * V_2 )
return - V_50 ;
}
F_3 ( V_51 , L_9 ,
V_9 , V_37 ) ;
V_34 = * V_2 ;
V_35 = (struct V_23 * ) * V_2 ;
if ( V_9 == V_42 )
V_35 -> V_9 = F_20 ( V_42 ) ;
else
V_34 -> V_9 = F_20 ( V_41 ) ;
if ( ! V_28 )
return V_37 ;
F_21 ( & V_34 -> V_7 , & V_28 -> V_52 ) ;
V_34 -> V_11 = F_20 ( V_28 -> V_53 ) ;
V_34 -> V_12 = F_22 ( V_16 ) ;
V_34 -> V_10 = F_20 ( V_28 -> V_54 ) ;
V_34 -> V_13 = F_22 ( V_28 -> V_55 ) ;
if ( V_28 -> V_39 == V_42 ) {
V_38 = F_23 ( V_35 -> V_25 , V_28 -> V_56 ,
sizeof( V_35 -> V_25 ) ) ;
if ( V_38 >= sizeof( V_35 -> V_25 ) )
return - V_57 ;
V_22 = V_35 -> V_22 ;
} else {
V_22 = V_34 -> V_22 ;
}
for ( V_17 = 0 ; V_17 < V_16 ; V_17 ++ ) {
struct V_58 * V_59 = V_28 -> V_60 [ V_17 ] ;
F_24 ( F_25 ( & V_59 -> V_61 ) != 0 , L_10 V_8
L_11 , F_4 ( & V_34 -> V_7 ) ,
V_17 , V_16 , V_59 -> V_62 ) ;
F_26 ( & V_59 -> V_61 , & V_22 [ V_17 ] . V_19 ) ;
V_22 [ V_17 ] . V_63 = F_20 ( V_59 -> V_64 ) ;
V_22 [ V_17 ] . V_20 = F_20 ( V_59 -> V_62 ) ;
}
return V_37 ;
}
T_1 F_14 ( struct V_31 * V_32 , T_2 V_65 , T_1 V_16 )
{
T_2 V_66 = V_67 ;
if ( ! V_16 )
V_16 = V_32 -> V_47 . V_68 ;
if ( V_16 > V_32 -> V_47 . V_69 )
V_16 = V_32 -> V_47 . V_69 ;
if ( ! V_16 )
V_16 = 1 ;
if ( V_32 -> V_45 . V_70 & V_71 &&
V_32 -> V_45 . V_46 )
V_66 = F_16 (
V_32 -> V_45 . V_46 , V_65 ) ;
if ( V_16 > V_66 )
V_16 = V_66 ;
return V_16 ;
}
static int F_27 ( void * V_4 , int V_72 , T_1 * V_16 )
{
int V_73 ;
if ( F_28 ( F_5 ( * ( T_2 * ) V_4 ) ) == NULL ) {
char * V_74 ;
int V_75 ;
F_13 ( L_12 ,
F_5 ( * ( T_2 * ) V_4 ) , V_72 ) ;
V_75 = V_72 * 2 + 1 ;
V_74 = F_19 ( V_75 , V_49 ) ;
if ( V_74 != NULL ) {
int V_17 ;
for ( V_17 = 0 ; V_17 < V_72 ; V_17 ++ )
sprintf ( V_74 + 2 * V_17 , L_13 , ( ( char * ) V_4 ) [ V_17 ] ) ;
V_74 [ V_75 - 1 ] = '\0' ;
F_13 ( L_14 , V_74 ) ;
F_18 ( V_74 ) ;
}
return - V_43 ;
}
V_73 = F_28 ( F_5 ( * ( T_2 * ) V_4 ) ) -> F_29 ( V_4 ,
V_72 , V_16 ) ;
return V_73 ;
}
int F_30 ( struct V_27 * * V_76 , T_1 V_16 ,
int V_77 , int V_65 )
{
int V_17 , V_78 ;
F_3 ( V_51 , L_15 , V_16 ) ;
* V_76 = F_31 ( V_16 , & V_78 ) ;
if ( ! * V_76 ) {
F_13 ( L_16 , V_16 ) ;
return - V_50 ;
}
F_32 ( & ( * V_76 ) -> V_79 , 1 ) ;
F_33 ( & ( * V_76 ) -> V_80 ) ;
( * V_76 ) -> V_39 = V_65 ;
( * V_76 ) -> V_44 = V_16 ;
( * V_76 ) -> V_81 = V_82 * V_16 ;
( * V_76 ) -> V_54 = V_77 ;
( * V_76 ) -> V_56 [ 0 ] = '\0' ;
( * V_76 ) -> V_55 = 0 ;
if ( V_16 > 0 )
( * V_76 ) -> V_60 [ 0 ] -> V_62 = ~ 0 ;
for ( V_17 = 0 ; V_17 < V_16 ; V_17 ++ )
F_34 ( ( * V_76 ) -> V_60 [ V_17 ] ) ;
return V_78 ;
}
int F_35 ( struct V_27 * * V_76 )
{
struct V_27 * V_28 = * V_76 ;
int V_83 ;
* V_76 = NULL ;
F_36 ( F_37 ( & V_28 -> V_79 ) > 0 ) ;
V_83 = F_38 ( & V_28 -> V_79 ) ;
if ( V_83 == 0 ) {
F_36 ( F_28 ( V_28 -> V_39 ) != NULL ) ;
F_28 ( V_28 -> V_39 ) -> F_39 ( V_28 ) ;
}
return V_83 ;
}
int F_40 ( struct V_26 * exp , struct V_27 * * V_76 ,
struct V_3 * V_4 , int V_72 )
{
struct V_29 * V_30 = F_12 ( exp ) ;
struct V_31 * V_32 = & V_30 -> V_33 . V_32 ;
int V_73 = 0 , V_78 ;
T_1 V_16 ;
T_2 V_65 ;
T_2 V_77 ;
if ( V_4 ) {
V_73 = F_27 ( V_4 , V_72 , & V_16 ) ;
if ( V_73 )
return V_73 ;
V_65 = F_5 ( V_4 -> V_9 ) ;
V_77 = F_5 ( V_4 -> V_10 ) ;
} else {
V_65 = V_40 ;
V_16 = F_14 ( V_32 , V_65 , 0 ) ;
V_77 = V_84 ;
}
if ( ! V_76 ) {
F_41 () ;
return F_42 ( V_16 ) ;
}
if ( * V_76 && ! V_4 ) {
F_35 ( V_76 ) ;
return 0 ;
}
V_78 = F_30 ( V_76 , V_16 , V_77 , V_65 ) ;
if ( V_78 < 0 )
return V_78 ;
if ( ! V_4 )
return V_78 ;
F_36 ( F_28 ( V_65 ) != NULL ) ;
V_73 = F_28 ( V_65 ) -> F_43 ( V_32 , * V_76 , V_4 ) ;
if ( V_73 ) {
F_35 ( V_76 ) ;
return V_73 ;
}
return V_78 ;
}
int F_44 ( struct V_26 * exp , struct V_27 * V_28 ,
struct V_85 * V_86 )
{
struct V_87 V_88 ;
struct V_3 * V_89 = NULL ;
int V_73 , V_37 ;
int V_90 ;
T_3 V_91 ;
if ( ! V_28 )
return - V_92 ;
V_91 = F_45 () ;
F_46 ( V_93 ) ;
V_90 = sizeof( struct V_94 ) ;
if ( F_47 ( & V_88 , V_86 , V_90 ) ) {
V_73 = - V_95 ;
goto V_96;
} else if ( ( V_88 . V_9 != V_97 ) &&
( V_88 . V_9 != V_98 ) ) {
V_73 = - V_43 ;
goto V_96;
}
if ( V_88 . V_12 &&
( V_88 . V_12 < V_28 -> V_44 ) ) {
V_88 . V_12 = V_28 -> V_44 ;
V_73 = F_48 ( V_86 , & V_88 , V_90 ) ;
V_73 = - V_99 ;
goto V_96;
}
V_73 = F_11 ( exp , & V_89 , V_28 ) ;
if ( V_73 < 0 )
goto V_96;
V_37 = V_73 ;
V_73 = 0 ;
F_49 ( sizeof( V_88 ) == sizeof( struct V_23 ) ) ;
F_49 ( sizeof( V_88 . V_22 [ 0 ] ) == sizeof( V_89 -> V_22 [ 0 ] ) ) ;
if ( ( F_20 ( V_40 ) != V_40 ) &&
( ( V_89 -> V_9 == F_20 ( V_41 ) ) ||
( V_89 -> V_9 == F_20 ( V_42 ) ) ) ) {
F_50 ( V_89 ) ;
F_51 (
(struct V_100 * ) V_89 -> V_22 ,
V_89 -> V_12 ) ;
}
if ( V_88 . V_9 == V_97 ) {
if ( V_89 -> V_9 == V_42 ) {
memmove ( ( char * ) ( & V_89 -> V_12 ) +
sizeof( V_89 -> V_12 ) ,
( (struct V_23 * ) V_89 ) -> V_22 ,
V_89 -> V_12 *
sizeof( struct V_36 ) ) ;
V_37 -= V_101 ;
}
} else {
V_90 = sizeof( struct V_87 ) ;
}
if ( V_88 . V_12 == 0 )
V_37 = V_90 ;
else if ( V_88 . V_12 < V_89 -> V_12 ) {
V_73 = - V_99 ;
goto V_96;
}
V_88 . V_12 = V_89 -> V_12 ;
V_88 . V_13 = V_89 -> V_13 ;
( (struct V_85 * ) V_89 ) -> V_13 = V_88 . V_13 ;
( (struct V_85 * ) V_89 ) -> V_12 = V_88 . V_12 ;
if ( F_48 ( V_86 , V_89 , V_37 ) )
V_73 = - V_95 ;
F_52 ( exp , & V_89 ) ;
V_96:
F_46 ( V_91 ) ;
return V_73 ;
}
