struct V_1 *
F_1 ( int V_2 , int V_3 , int V_4 )
{
int V_5 , V_6 = - 1 ;
struct V_1 * V_7 ;
if ( ! V_8 )
return NULL ;
F_2 ( & V_8 -> V_9 ) ;
for ( V_5 = 0 ; V_5 < V_10 ; V_5 ++ )
if ( ! V_8 -> V_11 [ V_5 ] . V_12 ) {
V_8 -> V_11 [ V_5 ] . V_12 = 0xfffffffful ;
V_6 = V_5 ;
break;
}
F_3 ( & V_8 -> V_9 ) ;
if ( V_6 < 0 )
return NULL ;
V_7 = F_4 ( sizeof( struct V_1 ) + V_4 , V_13 ) ;
if ( ! V_7 )
goto error;
V_7 -> V_6 = V_6 ;
if ( V_4 )
V_7 -> V_14 = ( void * ) V_7 + sizeof( struct V_1 ) ;
V_7 -> V_15 = F_5 ( V_8 -> V_16 , V_7 -> V_6 ) ;
if ( ! V_7 -> V_15 )
goto error;
if ( V_2 ) {
V_7 -> V_17 = F_6 ( sizeof( void * ) * V_2 , V_13 ) ;
if ( ! V_7 -> V_17 )
goto error;
V_7 -> V_18 = F_7 ( V_2 * V_3 , 4 , & V_7 -> V_19 ) ;
if ( ! V_7 -> V_18 )
goto error;
memset ( V_7 -> V_18 , 0x00 , V_2 * V_3 ) ;
V_7 -> V_20 = V_2 ;
V_7 -> V_3 = V_3 ;
}
return V_7 ;
error:
if ( V_7 ) {
if ( V_7 -> V_15 )
F_8 ( V_7 -> V_15 ) ;
F_9 ( V_7 -> V_18 ) ;
F_10 ( V_7 -> V_17 ) ;
F_10 ( V_7 ) ;
}
V_8 -> V_11 [ V_6 ] . V_12 = 0 ;
return NULL ;
}
void
F_11 ( struct V_1 * V_7 )
{
F_12 ( V_7 -> V_6 ) ;
V_8 -> V_11 [ V_7 -> V_6 ] . V_21 = 0 ;
V_8 -> V_11 [ V_7 -> V_6 ] . V_12 = 0 ;
F_8 ( V_7 -> V_15 ) ;
F_9 ( V_7 -> V_18 ) ;
F_10 ( V_7 -> V_17 ) ;
F_10 ( V_7 ) ;
}
int
F_13 ( int V_22 , T_1 * V_23 )
{
struct V_24 * V_25 = (struct V_24 * ) V_23 ;
struct V_26 * V_11 ;
T_1 * V_27 , * V_28 , * V_29 ;
T_1 * V_30 , * V_31 , * V_32 ;
if ( V_25 -> V_33 != V_34 ) {
F_14 (KERN_ERR DRIVER_NAME
L_1 ) ;
return - V_35 ;
}
if ( ( V_22 < 0 ) || ( V_22 >= V_10 ) ) {
F_14 (KERN_ERR DRIVER_NAME
L_2 , task) ;
return - V_35 ;
}
V_11 = & V_8 -> V_11 [ V_22 ] ;
if ( V_11 -> V_21 ) {
V_27 = F_15 ( V_22 ) ;
if ( V_25 -> V_36 != F_16 ( V_22 ) ) {
F_14 (KERN_ERR DRIVER_NAME
L_3
L_4 ,
task,
hdr->desc_size,
bcom_task_num_descs(task)) ;
return - V_35 ;
}
} else {
T_2 V_37 ;
V_27 = F_7 ( V_25 -> V_36 * sizeof( T_1 ) , 4 , & V_37 ) ;
if ( ! V_27 )
return - V_38 ;
V_11 -> V_21 = V_37 ;
V_11 -> V_12 = V_37 + ( ( V_25 -> V_36 - 1 ) * sizeof( T_1 ) ) ;
}
V_28 = F_17 ( V_22 ) ;
V_29 = F_18 ( V_22 ) ;
memset ( V_28 , 0x00 , V_39 ) ;
memset ( V_29 , 0x00 , V_40 ) ;
V_30 = ( T_1 * ) ( V_25 + 1 ) ;
V_31 = V_30 + V_25 -> V_36 ;
V_32 = V_31 + V_25 -> V_41 ;
memcpy ( V_27 , V_30 , V_25 -> V_36 * sizeof( T_1 ) ) ;
memcpy ( V_28 + V_25 -> V_42 , V_31 , V_25 -> V_41 * sizeof( T_1 ) ) ;
memcpy ( V_29 , V_32 , V_25 -> V_43 * sizeof( T_1 ) ) ;
return 0 ;
}
void
F_19 ( int V_22 , int V_44 )
{
int V_5 ;
int V_45 ;
T_1 * V_27 ;
int V_46 ;
F_20 ( V_22 , V_44 ) ;
V_27 = F_15 ( V_22 ) ;
V_46 = 1 ;
V_45 = F_16 ( V_22 ) ;
for ( V_5 = 0 ; V_5 < V_45 ; V_5 ++ , V_27 ++ ) {
if ( ! F_21 ( * V_27 ) )
continue;
if ( V_46 )
if ( F_22 ( * V_27 ) != V_47 )
F_23 ( V_27 , V_44 ) ;
V_46 = ! F_24 ( * V_27 ) ;
}
}
void
F_25 ( struct V_1 * V_7 )
{
F_26 ( V_7 -> V_6 ) ;
}
void
F_27 ( struct V_1 * V_7 )
{
F_12 ( V_7 -> V_6 ) ;
}
static int F_28 ( void )
{
int V_22 ;
T_2 V_48 , V_49 , V_50 , V_51 ;
unsigned int V_52 , V_53 , V_41 , V_54 ;
V_52 = V_10 * sizeof( struct V_26 ) ;
V_53 = V_10 * V_55 ;
V_41 = V_10 * ( V_39 + V_40 ) ;
V_54 = V_56 ;
V_8 -> V_11 = F_7 ( V_52 , sizeof( T_1 ) , & V_48 ) ;
V_8 -> V_57 = F_7 ( V_53 , V_58 , & V_49 ) ;
V_8 -> V_28 = F_7 ( V_41 , V_59 , & V_50 ) ;
V_8 -> V_60 = F_7 ( V_54 , V_61 , & V_51 ) ;
if ( ! V_8 -> V_11 || ! V_8 -> V_57 || ! V_8 -> V_28 || ! V_8 -> V_60 ) {
F_14 ( V_62 L_5 ) ;
F_9 ( V_8 -> V_11 ) ;
F_9 ( V_8 -> V_57 ) ;
F_9 ( V_8 -> V_28 ) ;
F_9 ( V_8 -> V_60 ) ;
return - V_38 ;
}
memset ( V_8 -> V_11 , 0x00 , V_52 ) ;
memset ( V_8 -> V_57 , 0x00 , V_53 ) ;
memset ( V_8 -> V_28 , 0x00 , V_41 ) ;
memset ( V_8 -> V_60 , 0x00 , V_54 ) ;
memcpy ( & V_8 -> V_60 [ 48 ] , V_63 , sizeof( V_63 ) ) ;
for ( V_22 = 0 ; V_22 < V_10 ; V_22 ++ )
{
F_29 ( & V_8 -> V_64 -> V_65 [ V_22 ] , 0 ) ;
F_30 ( & V_8 -> V_64 -> V_66 [ V_22 ] , 0 ) ;
V_8 -> V_11 [ V_22 ] . V_67 = V_49 ;
V_8 -> V_11 [ V_22 ] . V_28 = V_50 ;
V_8 -> V_11 [ V_22 ] . V_60 = V_51 ;
V_50 += V_39 + V_40 ;
V_49 += V_55 ;
}
F_31 ( & V_8 -> V_64 -> V_68 , V_48 ) ;
F_30 ( & V_8 -> V_64 -> V_66 [ V_47 ] , V_69 ) ;
if ( ( F_32 ( V_70 ) & V_71 ) == V_72 )
F_33 () ;
F_34 ( & V_8 -> V_9 ) ;
return 0 ;
}
static void
F_35 ( void )
{
int V_22 ;
for ( V_22 = 0 ; V_22 < V_10 ; V_22 ++ )
{
F_29 ( & V_8 -> V_64 -> V_65 [ V_22 ] , 0 ) ;
F_30 ( & V_8 -> V_64 -> V_66 [ V_22 ] , 0 ) ;
}
F_31 ( & V_8 -> V_64 -> V_68 , 0ul ) ;
F_9 ( V_8 -> V_11 ) ;
F_9 ( V_8 -> V_57 ) ;
F_9 ( V_8 -> V_28 ) ;
F_9 ( V_8 -> V_60 ) ;
}
static int F_36 ( struct V_73 * V_74 )
{
struct V_75 * V_76 ;
struct V_77 V_78 ;
int V_79 ;
F_14 ( V_80 L_6 ) ;
F_37 ( V_74 -> V_81 . V_82 ) ;
V_76 = F_38 ( NULL , V_83 ) ;
if ( ! V_76 ) {
F_14 (KERN_ERR DRIVER_NAME L_7
L_8 ) ;
V_79 = - V_84 ;
goto V_85;
}
V_79 = F_39 ( V_76 , V_86 ) ;
F_40 ( V_76 ) ;
if ( V_79 ) {
F_14 (KERN_ERR DRIVER_NAME L_7
L_9 ) ;
goto V_85;
}
V_8 = F_4 ( sizeof( struct V_87 ) , V_13 ) ;
if ( ! V_8 ) {
V_79 = - V_38 ;
goto V_88;
}
V_8 -> V_16 = V_74 -> V_81 . V_82 ;
if ( F_41 ( V_74 -> V_81 . V_82 , 0 , & V_78 ) ) {
F_14 (KERN_ERR DRIVER_NAME L_7
L_10 ) ;
V_79 = - V_35 ;
goto V_88;
}
if ( ! F_42 ( V_78 . V_21 , F_43 ( & V_78 ) ,
V_86 ) ) {
F_14 (KERN_ERR DRIVER_NAME L_7
L_11 ) ;
V_79 = - V_89 ;
goto V_88;
}
V_8 -> V_90 = V_78 . V_21 ;
V_8 -> V_64 = F_44 ( V_78 . V_21 , sizeof( struct V_91 ) ) ;
if ( ! V_8 -> V_64 ) {
F_14 (KERN_ERR DRIVER_NAME L_7
L_12 ) ;
V_79 = - V_38 ;
goto V_92;
}
V_79 = F_28 () ;
if ( V_79 )
goto V_93;
F_14 ( V_80 L_13 ,
( long ) V_8 -> V_90 ) ;
return 0 ;
V_93:
F_45 ( V_8 -> V_64 ) ;
V_92:
F_46 ( V_78 . V_21 , sizeof( struct V_91 ) ) ;
V_88:
F_10 ( V_8 ) ;
F_47 () ;
V_85:
F_40 ( V_74 -> V_81 . V_82 ) ;
F_14 ( V_62 L_14 ) ;
return V_79 ;
}
static int F_48 ( struct V_73 * V_74 )
{
F_35 () ;
F_47 () ;
F_45 ( V_8 -> V_64 ) ;
F_46 ( V_8 -> V_90 , sizeof( struct V_91 ) ) ;
F_40 ( V_8 -> V_16 ) ;
F_10 ( V_8 ) ;
V_8 = NULL ;
return 0 ;
}
static int T_3
F_49 ( void )
{
return F_50 ( & V_94 ) ;
}
static void T_4
F_51 ( void )
{
F_52 ( & V_94 ) ;
}
