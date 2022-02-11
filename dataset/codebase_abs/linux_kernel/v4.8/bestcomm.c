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
if ( V_7 -> V_15 == V_17 )
goto error;
if ( V_2 ) {
V_7 -> V_18 = F_6 ( sizeof( void * ) * V_2 , V_13 ) ;
if ( ! V_7 -> V_18 )
goto error;
V_7 -> V_19 = F_7 ( V_2 * V_3 , 4 , & V_7 -> V_20 ) ;
if ( ! V_7 -> V_19 )
goto error;
memset ( V_7 -> V_19 , 0x00 , V_2 * V_3 ) ;
V_7 -> V_21 = V_2 ;
V_7 -> V_3 = V_3 ;
}
return V_7 ;
error:
if ( V_7 ) {
if ( V_7 -> V_15 != V_17 )
F_8 ( V_7 -> V_15 ) ;
F_9 ( V_7 -> V_19 ) ;
F_10 ( V_7 -> V_18 ) ;
F_10 ( V_7 ) ;
}
V_8 -> V_11 [ V_6 ] . V_12 = 0 ;
return NULL ;
}
void
F_11 ( struct V_1 * V_7 )
{
F_12 ( V_7 -> V_6 ) ;
V_8 -> V_11 [ V_7 -> V_6 ] . V_22 = 0 ;
V_8 -> V_11 [ V_7 -> V_6 ] . V_12 = 0 ;
F_8 ( V_7 -> V_15 ) ;
F_9 ( V_7 -> V_19 ) ;
F_10 ( V_7 -> V_18 ) ;
F_10 ( V_7 ) ;
}
int
F_13 ( int V_23 , T_1 * V_24 )
{
struct V_25 * V_26 = (struct V_25 * ) V_24 ;
struct V_27 * V_11 ;
T_1 * V_28 , * V_29 , * V_30 ;
T_1 * V_31 , * V_32 , * V_33 ;
if ( V_26 -> V_34 != V_35 ) {
F_14 (KERN_ERR DRIVER_NAME
L_1 ) ;
return - V_36 ;
}
if ( ( V_23 < 0 ) || ( V_23 >= V_10 ) ) {
F_14 (KERN_ERR DRIVER_NAME
L_2 , task) ;
return - V_36 ;
}
V_11 = & V_8 -> V_11 [ V_23 ] ;
if ( V_11 -> V_22 ) {
V_28 = F_15 ( V_23 ) ;
if ( V_26 -> V_37 != F_16 ( V_23 ) ) {
F_14 (KERN_ERR DRIVER_NAME
L_3
L_4 ,
task,
hdr->desc_size,
bcom_task_num_descs(task)) ;
return - V_36 ;
}
} else {
T_2 V_38 ;
V_28 = F_7 ( V_26 -> V_37 * sizeof( T_1 ) , 4 , & V_38 ) ;
if ( ! V_28 )
return - V_39 ;
V_11 -> V_22 = V_38 ;
V_11 -> V_12 = V_38 + ( ( V_26 -> V_37 - 1 ) * sizeof( T_1 ) ) ;
}
V_29 = F_17 ( V_23 ) ;
V_30 = F_18 ( V_23 ) ;
memset ( V_29 , 0x00 , V_40 ) ;
memset ( V_30 , 0x00 , V_41 ) ;
V_31 = ( T_1 * ) ( V_26 + 1 ) ;
V_32 = V_31 + V_26 -> V_37 ;
V_33 = V_32 + V_26 -> V_42 ;
memcpy ( V_28 , V_31 , V_26 -> V_37 * sizeof( T_1 ) ) ;
memcpy ( V_29 + V_26 -> V_43 , V_32 , V_26 -> V_42 * sizeof( T_1 ) ) ;
memcpy ( V_30 , V_33 , V_26 -> V_44 * sizeof( T_1 ) ) ;
return 0 ;
}
void
F_19 ( int V_23 , int V_45 )
{
int V_5 ;
int V_46 ;
T_1 * V_28 ;
int V_47 ;
F_20 ( V_23 , V_45 ) ;
V_28 = F_15 ( V_23 ) ;
V_47 = 1 ;
V_46 = F_16 ( V_23 ) ;
for ( V_5 = 0 ; V_5 < V_46 ; V_5 ++ , V_28 ++ ) {
if ( ! F_21 ( * V_28 ) )
continue;
if ( V_47 )
if ( F_22 ( * V_28 ) != V_48 )
F_23 ( V_28 , V_45 ) ;
V_47 = ! F_24 ( * V_28 ) ;
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
int V_23 ;
T_2 V_49 , V_50 , V_51 , V_52 ;
unsigned int V_53 , V_54 , V_42 , V_55 ;
V_53 = V_10 * sizeof( struct V_27 ) ;
V_54 = V_10 * V_56 ;
V_42 = V_10 * ( V_40 + V_41 ) ;
V_55 = V_57 ;
V_8 -> V_11 = F_7 ( V_53 , sizeof( T_1 ) , & V_49 ) ;
V_8 -> V_58 = F_7 ( V_54 , V_59 , & V_50 ) ;
V_8 -> V_29 = F_7 ( V_42 , V_60 , & V_51 ) ;
V_8 -> V_61 = F_7 ( V_55 , V_62 , & V_52 ) ;
if ( ! V_8 -> V_11 || ! V_8 -> V_58 || ! V_8 -> V_29 || ! V_8 -> V_61 ) {
F_14 ( V_63 L_5 ) ;
F_9 ( V_8 -> V_11 ) ;
F_9 ( V_8 -> V_58 ) ;
F_9 ( V_8 -> V_29 ) ;
F_9 ( V_8 -> V_61 ) ;
return - V_39 ;
}
memset ( V_8 -> V_11 , 0x00 , V_53 ) ;
memset ( V_8 -> V_58 , 0x00 , V_54 ) ;
memset ( V_8 -> V_29 , 0x00 , V_42 ) ;
memset ( V_8 -> V_61 , 0x00 , V_55 ) ;
memcpy ( & V_8 -> V_61 [ 48 ] , V_64 , sizeof( V_64 ) ) ;
for ( V_23 = 0 ; V_23 < V_10 ; V_23 ++ )
{
F_29 ( & V_8 -> V_65 -> V_66 [ V_23 ] , 0 ) ;
F_30 ( & V_8 -> V_65 -> V_67 [ V_23 ] , 0 ) ;
V_8 -> V_11 [ V_23 ] . V_68 = V_50 ;
V_8 -> V_11 [ V_23 ] . V_29 = V_51 ;
V_8 -> V_11 [ V_23 ] . V_61 = V_52 ;
V_51 += V_40 + V_41 ;
V_50 += V_56 ;
}
F_31 ( & V_8 -> V_65 -> V_69 , V_49 ) ;
F_30 ( & V_8 -> V_65 -> V_67 [ V_48 ] , V_70 ) ;
if ( ( F_32 ( V_71 ) & V_72 ) == V_73 )
F_33 () ;
F_34 ( & V_8 -> V_9 ) ;
return 0 ;
}
static void
F_35 ( void )
{
int V_23 ;
for ( V_23 = 0 ; V_23 < V_10 ; V_23 ++ )
{
F_29 ( & V_8 -> V_65 -> V_66 [ V_23 ] , 0 ) ;
F_30 ( & V_8 -> V_65 -> V_67 [ V_23 ] , 0 ) ;
}
F_31 ( & V_8 -> V_65 -> V_69 , 0ul ) ;
F_9 ( V_8 -> V_11 ) ;
F_9 ( V_8 -> V_58 ) ;
F_9 ( V_8 -> V_29 ) ;
F_9 ( V_8 -> V_61 ) ;
}
static int F_36 ( struct V_74 * V_75 )
{
struct V_76 * V_77 ;
struct V_78 V_79 ;
int V_80 ;
F_14 ( V_81 L_6 ) ;
F_37 ( V_75 -> V_82 . V_83 ) ;
V_77 = F_38 ( NULL , V_84 ) ;
if ( ! V_77 ) {
F_14 (KERN_ERR DRIVER_NAME L_7
L_8 ) ;
V_80 = - V_85 ;
goto V_86;
}
V_80 = F_39 ( V_77 , V_87 ) ;
F_40 ( V_77 ) ;
if ( V_80 ) {
F_14 (KERN_ERR DRIVER_NAME L_7
L_9 ) ;
goto V_86;
}
V_8 = F_4 ( sizeof( struct V_88 ) , V_13 ) ;
if ( ! V_8 ) {
V_80 = - V_39 ;
goto V_89;
}
V_8 -> V_16 = V_75 -> V_82 . V_83 ;
if ( F_41 ( V_75 -> V_82 . V_83 , 0 , & V_79 ) ) {
F_14 (KERN_ERR DRIVER_NAME L_7
L_10 ) ;
V_80 = - V_36 ;
goto V_89;
}
if ( ! F_42 ( V_79 . V_22 , F_43 ( & V_79 ) ,
V_87 ) ) {
F_14 (KERN_ERR DRIVER_NAME L_7
L_11 ) ;
V_80 = - V_90 ;
goto V_89;
}
V_8 -> V_91 = V_79 . V_22 ;
V_8 -> V_65 = F_44 ( V_79 . V_22 , sizeof( struct V_92 ) ) ;
if ( ! V_8 -> V_65 ) {
F_14 (KERN_ERR DRIVER_NAME L_7
L_12 ) ;
V_80 = - V_39 ;
goto V_93;
}
V_80 = F_28 () ;
if ( V_80 )
goto V_94;
F_14 ( V_81 L_13 ,
( long ) V_8 -> V_91 ) ;
return 0 ;
V_94:
F_45 ( V_8 -> V_65 ) ;
V_93:
F_46 ( V_79 . V_22 , sizeof( struct V_92 ) ) ;
V_89:
F_10 ( V_8 ) ;
F_47 () ;
V_86:
F_40 ( V_75 -> V_82 . V_83 ) ;
F_14 ( V_63 L_14 ) ;
return V_80 ;
}
static int F_48 ( struct V_74 * V_75 )
{
F_35 () ;
F_47 () ;
F_45 ( V_8 -> V_65 ) ;
F_46 ( V_8 -> V_91 , sizeof( struct V_92 ) ) ;
F_40 ( V_8 -> V_16 ) ;
F_10 ( V_8 ) ;
V_8 = NULL ;
return 0 ;
}
static int T_3
F_49 ( void )
{
return F_50 ( & V_95 ) ;
}
static void T_4
F_51 ( void )
{
F_52 ( & V_95 ) ;
}
