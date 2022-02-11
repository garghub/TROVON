static T_1 F_1 ( T_1 V_1 )
{
switch ( V_1 ) {
case ( V_2 ) :
return V_3 ;
case ( V_4 ) :
return V_2 ;
case ( V_3 ) :
default:
return V_5 ;
}
}
static int F_2 ( struct V_6 * V_7 ,
T_1 V_8 )
{
int V_9 = 0 ;
struct V_10 * V_11 ;
unsigned long V_12 ;
int V_13 ;
F_3 ( & V_7 -> V_14 ) ;
V_11 = (struct V_10 * ) V_7 -> V_11 ;
V_11 -> V_15 . V_16 = V_17 ;
V_11 -> V_18 = V_8 ;
V_11 -> V_19 = F_4 ( V_20 . V_21 ) ;
V_11 -> V_22 = F_4 ( V_20 . V_23 ) ;
V_11 -> V_24 = F_4 (
( void * ) ( ( unsigned long ) V_20 . V_23 +
V_25 ) ) ;
F_5 ( & V_20 . V_26 , V_12 ) ;
F_6 ( & V_7 -> V_27 ,
& V_20 . V_28 ) ;
F_7 ( & V_20 . V_26 , V_12 ) ;
V_9 = F_8 ( V_11 ,
sizeof( struct V_10 ) ) ;
if ( V_9 != 0 ) {
F_5 ( & V_20 . V_26 , V_12 ) ;
F_9 ( & V_7 -> V_27 ) ;
F_7 ( & V_20 . V_26 ,
V_12 ) ;
return V_9 ;
}
V_13 = F_10 ( & V_7 -> V_14 , 5 * V_29 ) ;
if ( V_13 == 0 ) {
F_5 ( & V_20 . V_26 ,
V_12 ) ;
F_9 ( & V_7 -> V_27 ) ;
F_7 ( & V_20 . V_26 ,
V_12 ) ;
return - V_30 ;
}
F_5 ( & V_20 . V_26 , V_12 ) ;
F_9 ( & V_7 -> V_27 ) ;
F_7 ( & V_20 . V_26 , V_12 ) ;
if ( V_7 -> V_31 . V_32 . V_33 ) {
V_20 . V_34 = V_35 ;
} else {
return - V_36 ;
}
return V_9 ;
}
int F_11 ( void )
{
int V_9 = 0 ;
struct V_6 * V_7 = NULL ;
T_1 V_8 ;
V_20 . V_34 = V_37 ;
V_20 . V_38 = F_12 ( L_1 ) ;
if ( ! V_20 . V_38 ) {
V_9 = - V_39 ;
goto V_40;
}
F_13 ( & V_20 . V_28 ) ;
F_14 ( & V_20 . V_26 ) ;
F_13 ( & V_20 . V_41 ) ;
F_14 ( & V_20 . V_42 ) ;
V_20 . V_21 =
( void * ) F_15 ( V_43 | V_44 , 0 ) ;
if ( V_20 . V_21 == NULL ) {
V_9 = - V_39 ;
goto V_40;
}
V_20 . V_45 = V_20 . V_21 ;
V_20 . V_46 =
( void * ) ( ( unsigned long ) V_20 . V_21 +
( V_25 >> 1 ) ) ;
V_20 . V_23 =
( void * ) F_15 ( ( V_43 | V_44 ) , 1 ) ;
if ( V_20 . V_23 == NULL ) {
V_9 = - V_39 ;
goto V_40;
}
V_7 = F_16 ( sizeof( * V_7 ) +
sizeof( struct V_10 ) ,
V_43 ) ;
if ( V_7 == NULL ) {
V_9 = - V_39 ;
goto V_40;
}
V_8 = V_47 ;
do {
V_9 = F_2 ( V_7 , V_8 ) ;
if ( V_9 == 0 )
break;
V_8 = F_1 ( V_8 ) ;
} while ( V_8 != V_5 );
if ( V_8 == V_5 )
goto V_40;
V_48 = V_8 ;
F_17 ( L_2 ,
V_49 , V_50 >> 16 ,
V_50 & 0xFFFF , V_51 ,
V_52 >> 24 , V_52 & 0xFFFFFF ,
V_8 >> 16 , V_8 & 0xFFFF ) ;
F_18 ( V_7 ) ;
return 0 ;
V_40:
F_19 ( L_3 ) ;
V_20 . V_34 = V_53 ;
if ( V_20 . V_38 )
F_20 ( V_20 . V_38 ) ;
if ( V_20 . V_21 ) {
F_21 ( ( unsigned long ) V_20 . V_21 , 0 ) ;
V_20 . V_21 = NULL ;
}
if ( V_20 . V_23 ) {
F_21 ( ( unsigned long ) V_20 . V_23 , 1 ) ;
V_20 . V_23 = NULL ;
}
F_18 ( V_7 ) ;
return V_9 ;
}
struct V_54 * F_22 ( T_2 V_55 )
{
struct V_54 * V_56 ;
struct V_54 * V_57 = NULL ;
unsigned long V_12 ;
F_5 ( & V_20 . V_42 , V_12 ) ;
F_23 (channel, &vmbus_connection.chn_list, listentry) {
if ( V_56 -> V_58 . V_59 == V_55 ) {
V_57 = V_56 ;
break;
}
}
F_7 ( & V_20 . V_42 , V_12 ) ;
return V_57 ;
}
static void F_24 ( T_2 V_55 )
{
struct V_54 * V_56 ;
unsigned long V_12 ;
void * V_60 ;
bool V_61 ;
T_2 V_62 ;
V_56 = F_22 ( V_55 ) ;
if ( ! V_56 ) {
F_19 ( L_4 , V_55 ) ;
return;
}
F_5 ( & V_56 -> V_63 , V_12 ) ;
if ( V_56 -> V_64 != NULL ) {
V_60 = V_56 -> V_65 ;
V_61 = V_56 -> V_66 ;
do {
F_25 ( & V_56 -> V_67 ) ;
V_56 -> V_64 ( V_60 ) ;
V_62 = F_26 ( & V_56 -> V_67 ) ;
} while ( V_61 && ( V_62 != 0 ) );
} else {
F_19 ( L_5 , V_55 ) ;
}
F_7 ( & V_56 -> V_63 , V_12 ) ;
}
void F_27 ( unsigned long V_68 )
{
T_2 V_69 ;
T_2 V_70 ;
int V_71 ;
T_2 V_55 ;
T_2 * V_45 = NULL ;
void * V_72 ;
int V_73 = F_28 () ;
union V_74 * V_75 ;
if ( ( V_48 == V_3 ) ||
( V_48 == V_2 ) ) {
V_70 = V_76 >> 5 ;
V_45 = V_20 . V_45 ;
} else {
V_70 = V_77 ;
V_72 = V_78 . V_79 [ V_73 ] ;
V_75 = (union V_74 * ) V_72 +
V_80 ;
V_45 = V_75 -> V_81 ;
}
if ( ! V_45 )
return;
for ( V_69 = 0 ; V_69 < V_70 ; V_69 ++ ) {
if ( ! V_45 [ V_69 ] )
continue;
for ( V_71 = 0 ; V_71 < 32 ; V_71 ++ ) {
if ( F_29 ( V_71 ,
( unsigned long * ) & V_45 [ V_69 ] ) ) {
V_55 = ( V_69 << 5 ) + V_71 ;
if ( V_55 == 0 )
continue;
F_24 ( V_55 ) ;
}
}
}
}
int F_8 ( void * V_82 , T_3 V_83 )
{
union V_84 V_85 ;
int V_9 = 0 ;
int V_86 = 0 ;
V_85 . V_87 = 0 ;
V_85 . V_88 . V_89 = V_90 ;
while ( V_86 < 3 ) {
V_9 = F_30 ( V_85 , 1 , V_82 , V_83 ) ;
if ( V_9 != V_91 )
return V_9 ;
V_86 ++ ;
F_31 ( 100 ) ;
}
return V_9 ;
}
int F_32 ( struct V_54 * V_56 )
{
T_2 V_59 = V_56 -> V_58 . V_59 ;
if ( ! V_56 -> V_92 ) {
F_33 ( V_59 & 31 ,
( unsigned long * ) V_20 . V_46 +
( V_59 >> 5 ) ) ;
}
return F_34 ( V_56 -> V_93 ) ;
}
