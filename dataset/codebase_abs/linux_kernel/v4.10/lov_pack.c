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
T_1 F_11 ( const struct V_26 * V_27 , void * V_28 ,
T_2 V_29 )
{
struct V_30 * V_22 ;
struct V_21 * V_31 = V_28 ;
struct V_23 * V_32 = V_28 ;
T_2 V_33 ;
unsigned int V_17 ;
V_33 = F_12 ( V_27 -> V_34 , V_27 -> V_35 ) ;
if ( ! V_29 )
return V_33 ;
if ( V_29 < V_33 )
return - V_36 ;
V_31 -> V_9 = F_13 ( V_27 -> V_35 ) ;
F_14 ( & V_31 -> V_7 , & V_27 -> V_37 ) ;
V_31 -> V_11 = F_13 ( V_27 -> V_38 ) ;
V_31 -> V_12 = F_15 ( V_27 -> V_34 ) ;
V_31 -> V_10 = F_13 ( V_27 -> V_39 ) ;
V_31 -> V_13 = F_15 ( V_27 -> V_40 ) ;
if ( V_27 -> V_35 == V_41 ) {
F_16 ( sizeof( V_27 -> V_42 ) ==
sizeof( V_32 -> V_25 ) ) ;
F_17 ( V_32 -> V_25 , V_27 -> V_42 ,
sizeof( V_32 -> V_25 ) ) ;
V_22 = V_32 -> V_22 ;
} else {
V_22 = V_31 -> V_22 ;
}
for ( V_17 = 0 ; V_17 < V_27 -> V_34 ; V_17 ++ ) {
struct V_43 * V_44 = V_27 -> V_45 [ V_17 ] ;
F_18 ( & V_44 -> V_46 , & V_22 [ V_17 ] . V_19 ) ;
V_22 [ V_17 ] . V_47 = F_13 ( V_44 -> V_48 ) ;
V_22 [ V_17 ] . V_20 = F_13 ( V_44 -> V_49 ) ;
}
return V_33 ;
}
T_3 F_19 ( struct V_50 * V_51 , T_4 V_52 , T_3 V_16 )
{
T_4 V_53 = V_54 ;
if ( ! V_16 )
V_16 = V_51 -> V_55 . V_56 ;
if ( V_16 > V_51 -> V_55 . V_57 )
V_16 = V_51 -> V_55 . V_57 ;
if ( ! V_16 )
V_16 = 1 ;
if ( V_51 -> V_58 . V_59 & V_60 &&
V_51 -> V_58 . V_61 )
V_53 = F_20 (
V_51 -> V_58 . V_61 , V_52 ) ;
if ( V_16 > V_53 )
V_16 = V_53 ;
return V_16 ;
}
static int F_21 ( void * V_4 , int V_62 , T_3 * V_16 )
{
int V_63 ;
if ( ! F_22 ( F_5 ( * ( T_4 * ) V_4 ) ) ) {
F_23 ( L_8 ,
F_5 ( * ( T_4 * ) V_4 ) , V_62 ) ;
F_23 ( L_9 , V_62 , V_4 ) ;
return - V_64 ;
}
V_63 = F_22 ( F_5 ( * ( T_4 * ) V_4 ) ) -> F_24 ( V_4 ,
V_62 ,
V_16 ) ;
return V_63 ;
}
struct V_26 * F_25 ( T_5 V_16 , T_6 V_65 , T_6 V_52 )
{
struct V_26 * V_27 ;
unsigned int V_17 ;
F_3 ( V_66 , L_10 , V_16 ) ;
V_27 = F_26 ( V_16 ) ;
if ( ! V_27 ) {
F_23 ( L_11 , V_16 ) ;
return F_27 ( - V_67 ) ;
}
F_28 ( & V_27 -> V_68 , 1 ) ;
F_29 ( & V_27 -> V_69 ) ;
V_27 -> V_35 = V_52 ;
V_27 -> V_34 = V_16 ;
V_27 -> V_70 = V_71 * V_16 ;
V_27 -> V_39 = V_65 ;
V_27 -> V_42 [ 0 ] = '\0' ;
V_27 -> V_40 = 0 ;
if ( V_16 > 0 )
V_27 -> V_45 [ 0 ] -> V_49 = ~ 0 ;
for ( V_17 = 0 ; V_17 < V_16 ; V_17 ++ )
F_30 ( V_27 -> V_45 [ V_17 ] ) ;
return V_27 ;
}
int F_31 ( struct V_26 * * V_72 )
{
struct V_26 * V_27 = * V_72 ;
int V_73 ;
* V_72 = NULL ;
F_32 ( F_33 ( & V_27 -> V_68 ) > 0 ) ;
V_73 = F_34 ( & V_27 -> V_68 ) ;
if ( V_73 == 0 )
F_22 ( V_27 -> V_35 ) -> F_35 ( V_27 ) ;
return V_73 ;
}
struct V_26 * F_36 ( struct V_50 * V_51 , struct V_3 * V_4 ,
T_2 V_33 )
{
struct V_26 * V_27 ;
T_5 V_16 ;
T_6 V_65 ;
T_6 V_52 ;
int V_63 ;
V_63 = F_21 ( V_4 , V_33 , & V_16 ) ;
if ( V_63 )
return F_27 ( V_63 ) ;
V_52 = F_5 ( V_4 -> V_9 ) ;
V_65 = F_5 ( V_4 -> V_10 ) ;
V_27 = F_25 ( V_16 , V_65 , V_52 ) ;
if ( F_37 ( V_27 ) )
return V_27 ;
F_32 ( F_22 ( V_52 ) ) ;
V_63 = F_22 ( V_52 ) -> F_38 ( V_51 , V_27 , V_4 ) ;
if ( V_63 ) {
F_31 ( & V_27 ) ;
return F_27 ( V_63 ) ;
}
return V_27 ;
}
int F_39 ( struct V_74 * V_75 , struct V_26 * V_27 ,
struct V_76 T_7 * V_77 )
{
struct V_78 V_79 ;
struct V_3 * V_80 ;
T_6 V_16 ;
T_1 V_33 ;
T_2 V_81 ;
T_2 V_82 ;
int V_63 ;
T_8 V_83 ;
if ( ! V_27 )
return - V_84 ;
V_83 = F_40 () ;
F_41 ( V_85 ) ;
if ( V_27 -> V_35 != V_86 && V_27 -> V_35 != V_41 ) {
F_23 ( L_12 ,
V_27 -> V_35 , V_86 , V_41 ) ;
V_63 = - V_87 ;
goto V_88;
}
if ( ! F_42 ( V_27 ) )
V_16 = V_27 -> V_34 ;
else
V_16 = 0 ;
V_82 = sizeof( struct V_89 ) ;
if ( F_43 ( & V_79 , V_77 , V_82 ) ) {
V_63 = - V_90 ;
goto V_88;
}
if ( V_79 . V_9 != V_91 &&
V_79 . V_9 != V_92 &&
V_79 . V_9 != V_93 ) {
V_63 = - V_64 ;
goto V_88;
}
if ( V_79 . V_12 &&
( V_79 . V_12 < V_27 -> V_34 ) ) {
V_79 . V_12 = V_16 ;
V_63 = F_44 ( V_77 , & V_79 , V_82 ) ;
V_63 = - V_94 ;
goto V_88;
}
V_81 = F_12 ( V_16 , V_27 -> V_35 ) ;
V_80 = F_45 ( V_81 , V_95 ) ;
if ( ! V_80 ) {
V_63 = - V_67 ;
goto V_88;
}
V_33 = F_11 ( V_27 , V_80 , V_81 ) ;
if ( V_33 < 0 ) {
V_63 = V_33 ;
goto V_96;
}
F_16 ( sizeof( V_79 ) == sizeof( struct V_23 ) ) ;
F_16 ( sizeof( V_79 . V_22 [ 0 ] ) == sizeof( V_80 -> V_22 [ 0 ] ) ) ;
if ( F_13 ( V_97 ) != V_97 &&
( V_80 -> V_9 == F_13 ( V_86 ) ||
V_80 -> V_9 == F_13 ( V_41 ) ) ) {
F_46 ( V_80 ) ;
F_47 (
(struct V_98 * ) V_80 -> V_22 ,
V_80 -> V_12 ) ;
}
if ( V_79 . V_9 == V_99 ) {
if ( V_80 -> V_9 == V_41 ) {
memmove ( ( (struct V_21 * ) V_80 ) -> V_22 ,
( (struct V_23 * ) V_80 ) -> V_22 ,
V_80 -> V_12 *
sizeof( struct V_30 ) ) ;
V_33 -= V_100 ;
}
} else {
V_82 = sizeof( struct V_78 ) ;
}
if ( V_79 . V_12 == 0 ) {
V_33 = V_82 ;
} else if ( V_79 . V_12 < V_80 -> V_12 ) {
V_63 = - V_94 ;
goto V_96;
}
V_79 . V_12 = V_80 -> V_12 ;
V_79 . V_13 = V_80 -> V_13 ;
( (struct V_76 * ) V_80 ) -> V_13 = V_79 . V_13 ;
( (struct V_76 * ) V_80 ) -> V_12 = V_79 . V_12 ;
if ( F_44 ( V_77 , V_80 , V_33 ) )
V_63 = - V_90 ;
else
V_63 = 0 ;
V_96:
F_48 ( V_80 ) ;
V_88:
F_41 ( V_83 ) ;
return V_63 ;
}
