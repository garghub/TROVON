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
V_13 -> V_26 =
F_5 ( F_6 () ) ;
V_21 . V_27 = F_6 () ;
} else {
V_13 -> V_26 = 0 ;
V_21 . V_27 = 0 ;
}
F_7 ( & V_21 . V_28 , V_14 ) ;
F_8 ( & V_9 -> V_29 ,
& V_21 . V_30 ) ;
F_9 ( & V_21 . V_28 , V_14 ) ;
V_11 = F_10 ( V_13 ,
sizeof( struct V_12 ) ,
true ) ;
if ( V_11 != 0 ) {
F_7 ( & V_21 . V_28 , V_14 ) ;
F_11 ( & V_9 -> V_29 ) ;
F_9 ( & V_21 . V_28 ,
V_14 ) ;
return V_11 ;
}
F_12 ( & V_9 -> V_15 ) ;
F_7 ( & V_21 . V_28 , V_14 ) ;
F_11 ( & V_9 -> V_29 ) ;
F_9 ( & V_21 . V_28 , V_14 ) ;
if ( V_9 -> V_31 . V_32 . V_33 ) {
V_21 . V_34 = V_35 ;
} else {
return - V_36 ;
}
return V_11 ;
}
int F_13 ( void )
{
int V_11 = 0 ;
struct V_8 * V_9 = NULL ;
T_1 V_10 ;
V_21 . V_34 = V_37 ;
V_21 . V_38 = F_14 ( L_1 ) ;
if ( ! V_21 . V_38 ) {
V_11 = - V_39 ;
goto V_40;
}
F_15 ( & V_21 . V_30 ) ;
F_16 ( & V_21 . V_28 ) ;
F_15 ( & V_21 . V_41 ) ;
F_17 ( & V_21 . V_42 ) ;
V_21 . V_22 =
( void * ) F_18 ( V_43 | V_44 , 0 ) ;
if ( V_21 . V_22 == NULL ) {
V_11 = - V_39 ;
goto V_40;
}
V_21 . V_45 = V_21 . V_22 ;
V_21 . V_46 =
( void * ) ( ( unsigned long ) V_21 . V_22 +
( V_47 >> 1 ) ) ;
V_21 . V_24 [ 0 ] = ( void * ) F_18 ( ( V_43 | V_44 ) , 0 ) ;
V_21 . V_24 [ 1 ] = ( void * ) F_18 ( ( V_43 | V_44 ) , 0 ) ;
if ( ( V_21 . V_24 [ 0 ] == NULL ) ||
( V_21 . V_24 [ 1 ] == NULL ) ) {
V_11 = - V_39 ;
goto V_40;
}
V_9 = F_19 ( sizeof( * V_9 ) +
sizeof( struct V_12 ) ,
V_43 ) ;
if ( V_9 == NULL ) {
V_11 = - V_39 ;
goto V_40;
}
V_10 = V_48 ;
do {
V_11 = F_2 ( V_9 , V_10 ) ;
if ( V_11 == - V_49 )
goto V_40;
if ( V_21 . V_34 == V_35 )
break;
V_10 = F_1 ( V_10 ) ;
} while ( V_10 != V_7 );
if ( V_10 == V_7 )
goto V_40;
V_50 = V_10 ;
F_20 ( L_2 ,
V_10 >> 16 , V_10 & 0xFFFF ) ;
F_21 ( V_9 ) ;
return 0 ;
V_40:
F_22 ( L_3 ) ;
V_21 . V_34 = V_51 ;
F_23 () ;
F_21 ( V_9 ) ;
return V_11 ;
}
void F_23 ( void )
{
F_24 ( false ) ;
if ( V_21 . V_38 ) {
F_25 ( V_21 . V_38 ) ;
F_26 ( V_21 . V_38 ) ;
}
if ( V_21 . V_22 ) {
F_27 ( ( unsigned long ) V_21 . V_22 , 0 ) ;
V_21 . V_22 = NULL ;
}
F_27 ( ( unsigned long ) V_21 . V_24 [ 0 ] , 0 ) ;
F_27 ( ( unsigned long ) V_21 . V_24 [ 1 ] , 0 ) ;
V_21 . V_24 [ 0 ] = NULL ;
V_21 . V_24 [ 1 ] = NULL ;
}
struct V_52 * F_28 ( T_2 V_53 )
{
struct V_52 * V_54 ;
struct V_52 * V_55 = NULL ;
struct V_56 * V_57 , * V_58 ;
struct V_52 * V_59 ;
F_29 ( ! F_30 ( & V_21 . V_42 ) ) ;
F_31 (channel, &vmbus_connection.chn_list, listentry) {
if ( V_54 -> V_60 . V_61 == V_53 ) {
V_55 = V_54 ;
break;
} else if ( ! F_32 ( & V_54 -> V_62 ) ) {
F_33 (cur, tmp, &channel->sc_list) {
V_59 = F_34 ( V_57 , struct V_52 ,
V_62 ) ;
if ( V_59 -> V_60 . V_61 == V_53 ) {
V_55 = V_59 ;
break;
}
}
}
}
return V_55 ;
}
void F_35 ( unsigned long V_63 )
{
struct V_52 * V_54 = ( void * ) V_63 ;
unsigned long V_64 = V_65 + 2 ;
do {
void (* F_36)( void * );
F_36 = F_37 ( V_54 -> V_66 ) ;
if ( F_38 ( F_36 == NULL ) )
return;
(* F_36)( V_54 -> V_67 ) ;
if ( V_54 -> V_68 != V_69 )
return;
if ( F_39 ( F_40 ( & V_54 -> V_70 ) == 0 ) )
return;
F_41 ( & V_54 -> V_70 ) ;
} while ( F_39 ( F_42 ( V_65 , V_64 ) ) );
F_43 ( & V_54 -> V_71 ) ;
}
int F_10 ( void * V_72 , T_3 V_73 , bool V_74 )
{
union V_75 V_76 ;
int V_11 = 0 ;
int V_77 = 0 ;
T_2 V_78 = 1 ;
V_76 . V_79 = 0 ;
V_76 . V_80 . V_81 = V_82 ;
while ( V_77 < 100 ) {
V_11 = F_44 ( V_76 , 1 , V_72 , V_73 ) ;
switch ( V_11 ) {
case V_83 :
V_11 = - V_84 ;
break;
case V_85 :
case V_86 :
V_11 = - V_87 ;
break;
case V_88 :
return V_11 ;
default:
F_22 ( L_4 , V_11 ) ;
return - V_89 ;
}
V_77 ++ ;
if ( V_74 && V_78 > 1000 )
F_45 ( V_78 / 1000 ) ;
else if ( V_78 < V_90 * 1000 )
F_46 ( V_78 ) ;
else
F_47 ( V_78 / 1000 ) ;
if ( V_77 < 22 )
V_78 *= 2 ;
}
return V_11 ;
}
void F_48 ( struct V_52 * V_54 )
{
T_2 V_61 = V_54 -> V_60 . V_61 ;
if ( ! V_54 -> V_91 )
F_49 ( V_61 ) ;
F_50 ( V_92 , V_54 -> V_93 ) ;
}
