static T_1 F_1 ( T_1 V_1 )
{
switch ( V_1 ) {
case ( V_2 ) :
return V_3 ;
case ( V_4 ) :
return V_2 ;
case ( V_5 ) :
return V_4 ;
case ( V_6 ) :
return V_5 ;
case ( V_3 ) :
default:
return V_7 ;
}
}
static int F_2 ( struct V_8 * V_9 ,
T_1 V_10 )
{
int V_11 = 0 ;
struct V_12 * V_13 ;
unsigned long V_14 ;
F_3 ( & V_9 -> V_15 ) ;
V_13 = (struct V_12 * ) V_9 -> V_13 ;
V_13 -> V_16 . V_17 = V_18 ;
V_13 -> V_19 = V_10 ;
V_13 -> V_20 = F_4 ( V_21 . V_22 ) ;
V_13 -> V_23 = F_4 ( V_21 . V_24 [ 0 ] ) ;
V_13 -> V_25 = F_4 ( V_21 . V_24 [ 1 ] ) ;
if ( V_10 >= V_5 ) {
V_13 -> V_26 = V_27 . V_28 [ F_5 () ] ;
V_21 . V_29 = F_5 () ;
} else {
V_13 -> V_26 = 0 ;
V_21 . V_29 = 0 ;
}
F_6 ( & V_21 . V_30 , V_14 ) ;
F_7 ( & V_9 -> V_31 ,
& V_21 . V_32 ) ;
F_8 ( & V_21 . V_30 , V_14 ) ;
V_11 = F_9 ( V_13 ,
sizeof( struct V_12 ) ,
true ) ;
if ( V_11 != 0 ) {
F_6 ( & V_21 . V_30 , V_14 ) ;
F_10 ( & V_9 -> V_31 ) ;
F_8 ( & V_21 . V_30 ,
V_14 ) ;
return V_11 ;
}
F_11 ( & V_9 -> V_15 ) ;
F_6 ( & V_21 . V_30 , V_14 ) ;
F_10 ( & V_9 -> V_31 ) ;
F_8 ( & V_21 . V_30 , V_14 ) ;
if ( V_9 -> V_33 . V_34 . V_35 ) {
V_21 . V_36 = V_37 ;
} else {
return - V_38 ;
}
return V_11 ;
}
int F_12 ( void )
{
int V_11 = 0 ;
struct V_8 * V_9 = NULL ;
T_1 V_10 ;
V_21 . V_36 = V_39 ;
V_21 . V_40 = F_13 ( L_1 ) ;
if ( ! V_21 . V_40 ) {
V_11 = - V_41 ;
goto V_42;
}
F_14 ( & V_21 . V_32 ) ;
F_15 ( & V_21 . V_30 ) ;
F_14 ( & V_21 . V_43 ) ;
F_16 ( & V_21 . V_44 ) ;
V_21 . V_22 =
( void * ) F_17 ( V_45 | V_46 , 0 ) ;
if ( V_21 . V_22 == NULL ) {
V_11 = - V_41 ;
goto V_42;
}
V_21 . V_47 = V_21 . V_22 ;
V_21 . V_48 =
( void * ) ( ( unsigned long ) V_21 . V_22 +
( V_49 >> 1 ) ) ;
V_21 . V_24 [ 0 ] = ( void * ) F_17 ( ( V_45 | V_46 ) , 0 ) ;
V_21 . V_24 [ 1 ] = ( void * ) F_17 ( ( V_45 | V_46 ) , 0 ) ;
if ( ( V_21 . V_24 [ 0 ] == NULL ) ||
( V_21 . V_24 [ 1 ] == NULL ) ) {
V_11 = - V_41 ;
goto V_42;
}
V_9 = F_18 ( sizeof( * V_9 ) +
sizeof( struct V_12 ) ,
V_45 ) ;
if ( V_9 == NULL ) {
V_11 = - V_41 ;
goto V_42;
}
V_10 = V_50 ;
do {
V_11 = F_2 ( V_9 , V_10 ) ;
if ( V_11 == - V_51 )
goto V_42;
if ( V_21 . V_36 == V_37 )
break;
V_10 = F_1 ( V_10 ) ;
} while ( V_10 != V_7 );
if ( V_10 == V_7 )
goto V_42;
V_52 = V_10 ;
F_19 ( L_2 ,
V_10 >> 16 , V_10 & 0xFFFF ) ;
F_20 ( V_9 ) ;
return 0 ;
V_42:
F_21 ( L_3 ) ;
V_21 . V_36 = V_53 ;
F_22 () ;
F_20 ( V_9 ) ;
return V_11 ;
}
void F_22 ( void )
{
F_23 ( false ) ;
if ( V_21 . V_40 ) {
F_24 ( V_21 . V_40 ) ;
F_25 ( V_21 . V_40 ) ;
}
if ( V_21 . V_22 ) {
F_26 ( ( unsigned long ) V_21 . V_22 , 0 ) ;
V_21 . V_22 = NULL ;
}
F_26 ( ( unsigned long ) V_21 . V_24 [ 0 ] , 0 ) ;
F_26 ( ( unsigned long ) V_21 . V_24 [ 1 ] , 0 ) ;
V_21 . V_24 [ 0 ] = NULL ;
V_21 . V_24 [ 1 ] = NULL ;
}
struct V_54 * F_27 ( T_2 V_55 )
{
struct V_54 * V_56 ;
struct V_54 * V_57 = NULL ;
struct V_58 * V_59 , * V_60 ;
struct V_54 * V_61 ;
F_28 ( ! F_29 ( & V_21 . V_44 ) ) ;
F_30 (channel, &vmbus_connection.chn_list, listentry) {
if ( V_56 -> V_62 . V_63 == V_55 ) {
V_57 = V_56 ;
break;
} else if ( ! F_31 ( & V_56 -> V_64 ) ) {
F_32 (cur, tmp, &channel->sc_list) {
V_61 = F_33 ( V_59 , struct V_54 ,
V_64 ) ;
if ( V_61 -> V_62 . V_63 == V_55 ) {
V_57 = V_61 ;
break;
}
}
}
}
return V_57 ;
}
void F_34 ( unsigned long V_65 )
{
struct V_54 * V_56 = ( void * ) V_65 ;
unsigned long V_66 = V_67 + 2 ;
do {
void (* F_35)( void * );
F_35 = F_36 ( V_56 -> V_68 ) ;
if ( F_37 ( F_35 == NULL ) )
return;
(* F_35)( V_56 -> V_69 ) ;
if ( V_56 -> V_70 != V_71 )
return;
if ( F_38 ( F_39 ( & V_56 -> V_72 ) == 0 ) )
return;
F_40 ( & V_56 -> V_72 ) ;
} while ( F_38 ( F_41 ( V_67 , V_66 ) ) );
F_42 ( & V_56 -> V_73 ) ;
}
int F_9 ( void * V_74 , T_3 V_75 , bool V_76 )
{
union V_77 V_78 ;
int V_11 = 0 ;
int V_79 = 0 ;
T_2 V_80 = 1 ;
V_78 . V_81 = 0 ;
V_78 . V_82 . V_83 = V_84 ;
while ( V_79 < 100 ) {
V_11 = F_43 ( V_78 , 1 , V_74 , V_75 ) ;
switch ( V_11 ) {
case V_85 :
V_11 = - V_86 ;
break;
case V_87 :
case V_88 :
V_11 = - V_89 ;
break;
case V_90 :
return V_11 ;
default:
F_21 ( L_4 , V_11 ) ;
return - V_91 ;
}
V_79 ++ ;
if ( V_76 && V_80 > 1000 )
F_44 ( V_80 / 1000 ) ;
else if ( V_80 < V_92 * 1000 )
F_45 ( V_80 ) ;
else
F_46 ( V_80 / 1000 ) ;
if ( V_79 < 22 )
V_80 *= 2 ;
}
return V_11 ;
}
void F_47 ( struct V_54 * V_56 )
{
T_2 V_63 = V_56 -> V_62 . V_63 ;
if ( ! V_56 -> V_93 )
F_48 ( V_63 ) ;
F_49 ( V_94 , V_56 -> V_95 , NULL ) ;
}
