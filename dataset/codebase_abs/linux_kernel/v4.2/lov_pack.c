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
void F_11 ( int V_1 , void * V_4 )
{
int V_26 ;
V_26 = F_5 ( ( (struct V_3 * ) V_4 ) -> V_9 ) ;
switch ( V_26 ) {
case V_27 :
F_9 ( V_1 , (struct V_21 * ) V_4 ) ;
break;
case V_28 :
F_10 ( V_1 , (struct V_23 * ) V_4 ) ;
break;
default:
F_3 ( V_1 , L_8 ,
V_26 , V_27 ) ;
F_1 ( V_1 , V_4 ) ;
break;
}
}
int F_12 ( struct V_29 * exp , struct V_3 * * V_2 ,
struct V_30 * V_31 )
{
struct V_32 * V_33 = F_13 ( exp ) ;
struct V_34 * V_35 = & V_33 -> V_36 . V_35 ;
struct V_21 * V_37 ;
struct V_23 * V_38 ;
T_1 V_16 ;
struct V_39 * V_22 ;
int V_40 , V_9 ;
int V_17 ;
int V_41 = 0 ;
if ( V_31 ) {
V_9 = V_31 -> V_42 ;
} else {
if ( V_2 && * V_2 )
V_9 = F_5 ( ( * V_2 ) -> V_9 ) ;
else
V_9 = V_43 ;
}
if ( ( V_9 != V_27 ) &&
( V_9 != V_28 ) ) {
F_14 ( L_9 ,
V_9 , V_27 , V_28 ) ;
return - V_44 ;
}
if ( V_31 ) {
if ( ! V_2 ) {
V_16 = F_15 ( V_35 , V_9 ,
V_31 -> V_45 ) ;
V_31 -> V_45 = V_16 ;
} else if ( ! F_16 ( V_31 ) ) {
V_16 = V_31 -> V_45 ;
} else {
V_16 = 0 ;
}
} else {
V_16 = F_17 (
V_35 -> V_46 . V_47 , V_9 ) ;
if ( V_16 > V_35 -> V_48 . V_49 )
V_16 = V_35 -> V_48 . V_49 ;
}
V_40 = F_18 ( V_16 , V_9 ) ;
if ( ! V_2 )
return V_40 ;
if ( * V_2 && ! V_31 ) {
V_16 = F_6 ( ( * V_2 ) -> V_12 ) ;
V_40 = F_18 ( V_16 , V_9 ) ;
F_19 ( * V_2 ) ;
* V_2 = NULL ;
return 0 ;
}
if ( ! * V_2 ) {
* V_2 = F_20 ( V_40 , V_50 ) ;
if ( ! * V_2 )
return - V_51 ;
}
F_3 ( V_52 , L_10 ,
V_9 , V_40 ) ;
V_37 = * V_2 ;
V_38 = (struct V_23 * ) * V_2 ;
if ( V_9 == V_28 )
V_38 -> V_9 = F_21 ( V_28 ) ;
else
V_37 -> V_9 = F_21 ( V_27 ) ;
if ( ! V_31 )
return V_40 ;
F_22 ( & V_37 -> V_7 , & V_31 -> V_53 ) ;
V_37 -> V_11 = F_21 ( V_31 -> V_54 ) ;
V_37 -> V_12 = F_23 ( V_16 ) ;
V_37 -> V_10 = F_21 ( V_31 -> V_55 ) ;
V_37 -> V_13 = F_23 ( V_31 -> V_56 ) ;
if ( V_31 -> V_42 == V_28 ) {
V_41 = F_24 ( V_38 -> V_25 , V_31 -> V_57 ,
sizeof( V_38 -> V_25 ) ) ;
if ( V_41 >= sizeof( V_38 -> V_25 ) )
return - V_58 ;
V_22 = V_38 -> V_22 ;
} else {
V_22 = V_37 -> V_22 ;
}
for ( V_17 = 0 ; V_17 < V_16 ; V_17 ++ ) {
struct V_59 * V_60 = V_31 -> V_61 [ V_17 ] ;
F_25 ( F_26 ( & V_60 -> V_62 ) != 0 , L_11 V_8
L_12 , F_4 ( & V_37 -> V_7 ) ,
V_17 , V_16 , V_60 -> V_63 ) ;
F_27 ( & V_60 -> V_62 , & V_22 [ V_17 ] . V_19 ) ;
V_22 [ V_17 ] . V_64 = F_21 ( V_60 -> V_65 ) ;
V_22 [ V_17 ] . V_20 = F_21 ( V_60 -> V_63 ) ;
}
return V_40 ;
}
T_1 F_15 ( struct V_34 * V_35 , T_2 V_26 , T_1 V_16 )
{
T_2 V_66 = V_67 ;
if ( ! V_16 )
V_16 = V_35 -> V_48 . V_68 ;
if ( V_16 > V_35 -> V_48 . V_69 )
V_16 = V_35 -> V_48 . V_69 ;
if ( ! V_16 )
V_16 = 1 ;
if ( V_35 -> V_46 . V_70 & V_71 &&
V_35 -> V_46 . V_47 )
V_66 = F_17 (
V_35 -> V_46 . V_47 , V_26 ) ;
if ( V_16 > V_66 )
V_16 = V_66 ;
return V_16 ;
}
static int F_28 ( void * V_4 , int V_72 , T_1 * V_16 )
{
int V_73 ;
if ( F_29 ( F_5 ( * ( T_2 * ) V_4 ) ) == NULL ) {
char * V_74 ;
int V_75 ;
F_14 ( L_13 ,
F_5 ( * ( T_2 * ) V_4 ) , V_72 ) ;
V_75 = V_72 * 2 + 1 ;
V_74 = F_20 ( V_75 , V_50 ) ;
if ( V_74 != NULL ) {
int V_17 ;
for ( V_17 = 0 ; V_17 < V_72 ; V_17 ++ )
sprintf ( V_74 + 2 * V_17 , L_14 , ( ( char * ) V_4 ) [ V_17 ] ) ;
V_74 [ V_75 - 1 ] = '\0' ;
F_14 ( L_15 , V_74 ) ;
F_19 ( V_74 ) ;
}
return - V_44 ;
}
V_73 = F_29 ( F_5 ( * ( T_2 * ) V_4 ) ) -> F_30 ( V_4 ,
V_72 , V_16 ) ;
return V_73 ;
}
int F_31 ( struct V_30 * * V_76 , T_1 V_16 ,
int V_77 , int V_26 )
{
int V_17 , V_78 ;
F_3 ( V_52 , L_16 , V_16 ) ;
* V_76 = F_32 ( V_16 , & V_78 ) ;
if ( ! * V_76 ) {
F_14 ( L_17 , V_16 ) ;
return - V_51 ;
}
F_33 ( & ( * V_76 ) -> V_79 , 1 ) ;
F_34 ( & ( * V_76 ) -> V_80 ) ;
( * V_76 ) -> V_42 = V_26 ;
( * V_76 ) -> V_45 = V_16 ;
( * V_76 ) -> V_81 = V_82 * V_16 ;
( * V_76 ) -> V_55 = V_77 ;
( * V_76 ) -> V_57 [ 0 ] = '\0' ;
( * V_76 ) -> V_56 = 0 ;
if ( V_16 > 0 )
( * V_76 ) -> V_61 [ 0 ] -> V_63 = ~ 0 ;
for ( V_17 = 0 ; V_17 < V_16 ; V_17 ++ )
F_35 ( ( * V_76 ) -> V_61 [ V_17 ] ) ;
return V_78 ;
}
int F_36 ( struct V_30 * * V_76 )
{
struct V_30 * V_31 = * V_76 ;
int V_83 ;
* V_76 = NULL ;
F_37 ( F_38 ( & V_31 -> V_79 ) > 0 ) ;
V_83 = F_39 ( & V_31 -> V_79 ) ;
if ( V_83 == 0 ) {
F_37 ( F_29 ( V_31 -> V_42 ) != NULL ) ;
F_29 ( V_31 -> V_42 ) -> F_40 ( V_31 ) ;
}
return V_83 ;
}
int F_41 ( struct V_29 * exp , struct V_30 * * V_76 ,
struct V_3 * V_4 , int V_72 )
{
struct V_32 * V_33 = F_13 ( exp ) ;
struct V_34 * V_35 = & V_33 -> V_36 . V_35 ;
int V_73 = 0 , V_78 ;
T_1 V_16 ;
T_2 V_26 ;
T_2 V_77 ;
if ( V_4 ) {
V_73 = F_28 ( V_4 , V_72 , & V_16 ) ;
if ( V_73 )
return V_73 ;
V_26 = F_5 ( V_4 -> V_9 ) ;
V_77 = F_5 ( V_4 -> V_10 ) ;
} else {
V_26 = V_43 ;
V_16 = F_15 ( V_35 , V_26 , 0 ) ;
V_77 = V_84 ;
}
if ( ! V_76 ) {
F_42 () ;
return F_43 ( V_16 ) ;
}
if ( * V_76 && ! V_4 ) {
F_36 ( V_76 ) ;
return 0 ;
}
V_78 = F_31 ( V_76 , V_16 , V_77 , V_26 ) ;
if ( V_78 < 0 )
return V_78 ;
if ( ! V_4 )
return V_78 ;
F_37 ( F_29 ( V_26 ) != NULL ) ;
V_73 = F_29 ( V_26 ) -> F_44 ( V_35 , * V_76 , V_4 ) ;
if ( V_73 ) {
F_36 ( V_76 ) ;
return V_73 ;
}
return V_78 ;
}
int F_45 ( struct V_29 * exp , struct V_30 * V_31 ,
struct V_85 * V_86 )
{
struct V_87 V_88 ;
struct V_3 * V_89 = NULL ;
int V_73 , V_40 ;
int V_90 ;
T_3 V_91 ;
if ( ! V_31 )
return - V_92 ;
V_91 = F_46 () ;
F_47 ( V_93 ) ;
V_90 = sizeof( struct V_94 ) ;
if ( F_48 ( & V_88 , V_86 , V_90 ) ) {
V_73 = - V_95 ;
goto V_96;
} else if ( ( V_88 . V_9 != V_97 ) &&
( V_88 . V_9 != V_98 ) ) {
V_73 = - V_44 ;
goto V_96;
}
if ( V_88 . V_12 &&
( V_88 . V_12 < V_31 -> V_45 ) ) {
V_88 . V_12 = V_31 -> V_45 ;
V_73 = F_49 ( V_86 , & V_88 , V_90 ) ;
V_73 = - V_99 ;
goto V_96;
}
V_73 = F_12 ( exp , & V_89 , V_31 ) ;
if ( V_73 < 0 )
goto V_96;
V_40 = V_73 ;
V_73 = 0 ;
F_50 ( sizeof( V_88 ) == sizeof( struct V_23 ) ) ;
F_50 ( sizeof( V_88 . V_22 [ 0 ] ) == sizeof( V_89 -> V_22 [ 0 ] ) ) ;
if ( ( F_21 ( V_43 ) != V_43 ) &&
( ( V_89 -> V_9 == F_21 ( V_27 ) ) ||
( V_89 -> V_9 == F_21 ( V_28 ) ) ) ) {
F_51 ( V_89 ) ;
F_52 (
(struct V_100 * ) V_89 -> V_22 ,
V_89 -> V_12 ) ;
}
if ( V_88 . V_9 == V_97 ) {
if ( V_89 -> V_9 == V_28 ) {
memmove ( ( char * ) ( & V_89 -> V_12 ) +
sizeof( V_89 -> V_12 ) ,
( (struct V_23 * ) V_89 ) -> V_22 ,
V_89 -> V_12 *
sizeof( struct V_39 ) ) ;
V_40 -= V_101 ;
}
} else {
V_90 = sizeof( struct V_87 ) ;
}
if ( V_88 . V_12 == 0 )
V_40 = V_90 ;
else if ( V_88 . V_12 < V_89 -> V_12 ) {
V_73 = - V_99 ;
goto V_96;
}
V_88 . V_12 = V_89 -> V_12 ;
V_88 . V_13 = V_89 -> V_13 ;
( (struct V_85 * ) V_89 ) -> V_13 = V_88 . V_13 ;
( (struct V_85 * ) V_89 ) -> V_12 = V_88 . V_12 ;
if ( F_49 ( V_86 , V_89 , V_40 ) )
V_73 = - V_95 ;
F_53 ( exp , & V_89 ) ;
V_96:
F_47 ( V_91 ) ;
return V_73 ;
}
