static void T_1 * T_2 F_1 ( T_3 V_1 , T_4 V_2 )
{
if ( ! V_1 || ! V_2 )
return NULL ;
if ( V_3 )
return F_2 ( V_1 , V_2 , V_4 ) ;
else
return F_3 ( V_1 , V_2 ) ;
}
static void T_2 F_4 ( void T_1 * V_5 , T_4 V_2 )
{
if ( ! V_5 || ! V_2 )
return;
if ( V_3 )
F_5 ( V_5 ) ;
else
F_6 ( V_5 , V_2 ) ;
}
static void F_7 ( unsigned long long V_6 ,
struct V_7 * V_8 )
{
F_8 ( L_1 ,
V_8 -> V_9 , V_6 ,
V_8 -> V_10 , V_8 -> V_11 , V_8 -> V_12 ,
V_8 -> V_13 ) ;
}
static int F_9 ( struct V_7 * V_14 )
{
T_5 V_15 = 0 ;
T_5 * V_16 = ( T_5 * ) V_14 ;
T_4 V_17 = V_14 -> V_10 ;
if ( V_17 > 0x100000 ) {
F_10 ( L_2 , V_17 ) ;
return - 1 ;
}
while ( V_17 -- )
V_15 += * V_16 ++ ;
if ( V_15 ) {
F_10 ( L_3 ,
V_14 -> V_18 , V_14 -> V_18 - V_15 ) ;
return - 1 ;
}
return 0 ;
}
static struct V_7 * F_11 ( T_3 V_6 )
{
struct V_7 * V_19 ;
T_4 V_17 ;
if ( ! F_12 ( V_20 , V_6 , sizeof( struct V_7 ) ) )
V_19 = F_1 ( V_6 , sizeof( struct V_7 ) ) ;
else
V_19 = ( void * ) V_21 + ( V_6 - V_20 ) ;
if ( F_12 ( V_19 , V_19 , V_19 -> V_10 ) )
return V_19 ;
V_17 = V_19 -> V_10 ;
if ( ! F_12 ( V_20 , V_6 , sizeof( struct V_7 ) ) )
F_4 ( V_19 , sizeof( struct V_7 ) ) ;
return F_1 ( V_6 , V_17 ) ;
}
static void F_13 ( struct V_7 * V_19 )
{
if ( ! F_12 ( V_21 , V_19 , V_19 -> V_10 ) )
F_4 ( V_19 , F_12 ( V_19 , V_19 , V_19 -> V_10 ) ?
sizeof( * V_19 ) : V_19 -> V_10 ) ;
}
static int F_14 ( struct V_7 * V_19 ,
struct V_22 * V_23 )
{
if ( strncmp ( V_19 -> V_9 , V_23 -> V_9 , V_24 )
|| ( V_23 -> V_12 && strncmp ( V_19 -> V_12 ,
V_23 -> V_12 , V_25 ) )
|| ( V_23 -> V_13 && strncmp ( V_19 -> V_13 ,
V_23 -> V_13 , V_26 ) ) )
return - 1 ;
return 0 ;
}
struct V_7 *
T_2 F_15 ( T_3 V_6 , struct V_22 * V_23 )
{
struct V_7 * V_19 ;
void * V_27 = NULL ;
V_19 = F_11 ( V_6 ) ;
if ( ! V_19 )
return F_16 ( - V_28 ) ;
if ( ! V_23 -> V_9 ) {
F_7 ( V_6 , V_19 ) ;
if ( F_9 ( V_19 ) )
V_27 = F_16 ( - V_29 ) ;
} else {
if ( ! F_14 ( V_19 , V_23 ) )
return V_19 ;
}
F_13 ( V_19 ) ;
return V_27 ;
}
struct V_7 * F_17 ( struct V_22 * V_23 )
{
struct V_7 * V_19 ;
T_4 V_30 , V_31 ;
V_30 = F_18 ( V_21 , T_3 ) ;
for ( V_31 = 0 ; V_31 < V_30 ; V_31 ++ ) {
V_19 = F_15 ( V_21 -> V_32 [ V_31 ] , V_23 ) ;
if ( ! F_19 ( V_19 ) && V_19 )
return V_19 ;
}
return NULL ;
}
void F_20 ( struct V_7 * V_19 )
{
F_13 ( V_19 ) ;
}
int F_21 ( char * V_33 , char * V_12 , char * V_13 ,
T_6 V_34 )
{
struct V_7 * V_14 = NULL ;
struct V_22 V_23 ;
int V_27 = - V_29 ;
if ( V_35 || ! V_34 || ! V_33 )
goto exit;
V_23 . V_9 = V_33 ;
V_23 . V_12 = V_12 ;
V_23 . V_13 = V_13 ;
V_14 = F_17 ( & V_23 ) ;
if ( ! V_14 )
goto exit;
V_27 = V_34 ( V_14 ) ;
F_20 ( V_14 ) ;
exit:
return V_27 ;
}
static int T_7 F_22 ( void )
{
struct V_22 V_23 = V_36 ;
int V_30 , V_31 ;
void * V_27 ;
V_21 = F_1 ( V_20 , sizeof( struct V_37 ) ) ;
if ( ! V_21 )
return - V_28 ;
V_30 = F_18 ( V_21 , T_3 ) ;
for ( V_31 = 0 ; V_31 < V_30 ; V_31 ++ ) {
V_27 = F_15 ( V_21 -> V_32 [ V_31 ] , & V_23 ) ;
if ( F_19 ( V_27 ) )
return F_23 ( V_27 ) ;
}
return 0 ;
}
static T_7 int F_24 ( void )
{
unsigned long V_38 , V_10 ;
void * V_39 ;
V_10 = V_40 - V_41 ;
V_39 = F_1 ( V_41 , V_10 ) ;
if ( ! V_39 )
return - 1 ;
for ( V_38 = 0 ; V_38 < V_10 ; V_38 += 16 ) {
struct V_7 * V_42 ;
V_42 = V_39 + V_38 ;
if ( strncmp ( V_42 -> V_9 , V_43 ,
V_24 ) )
continue;
if ( V_42 -> V_10 > V_44 )
continue;
F_7 ( V_41 + V_38 ,
V_42 ) ;
if ( F_9 ( V_42 ) )
continue;
if ( ! F_25 ( V_20 , V_20 + V_42 -> V_10 ) ) {
F_8 ( L_4 ,
V_20 , V_42 -> V_10 ) ;
continue;
}
V_20 = V_41 + V_38 ;
F_4 ( V_39 , V_10 ) ;
return 0 ;
}
F_4 ( V_39 , V_10 ) ;
return - 1 ;
}
static T_8 F_26 ( struct V_45 * V_46 , struct V_47 * V_48 ,
struct V_49 * V_50 , char * V_51 ,
T_9 V_38 , T_10 V_52 )
{
struct V_53 * V_54 =
F_27 ( V_50 , struct V_53 , V_55 ) ;
struct V_7 * V_19 = NULL ;
struct V_22 V_23 ;
T_8 V_56 ;
V_23 . V_9 = V_54 -> V_57 ;
V_23 . V_12 = NULL ;
V_23 . V_13 = NULL ;
if ( strncmp ( V_43 , V_54 -> V_57 , V_24 ) ) {
V_19 = F_17 ( & V_23 ) ;
if ( ! V_19 )
return 0 ;
V_56 = F_28 ( V_51 , V_52 , & V_38 ,
V_19 , V_19 -> V_10 ) ;
F_20 ( V_19 ) ;
} else
V_56 = F_28 ( V_51 , V_52 , & V_38 ,
V_21 , V_21 -> V_8 . V_10 ) ;
return V_56 ;
}
struct V_53 T_7 * F_29 ( T_3 V_6 )
{
struct V_53 * V_54 ;
struct V_7 * V_19 ;
int V_27 ;
V_54 = F_30 ( sizeof( struct V_53 ) , V_58 ) ;
if ( ! V_54 )
return NULL ;
V_19 = F_11 ( V_6 ) ;
if ( ! V_19 || ! V_19 -> V_9 [ 0 ] ) {
F_31 ( V_54 ) ;
return NULL ;
}
F_32 ( & V_54 -> V_55 . V_55 ) ;
memcpy ( V_54 -> V_57 , V_19 -> V_9 , V_24 ) ;
V_54 -> V_55 . V_2 = 0 ;
V_54 -> V_55 . V_59 = F_26 ;
V_54 -> V_55 . V_55 . V_57 = V_54 -> V_57 ;
V_54 -> V_55 . V_55 . V_60 = 0400 ;
V_27 = F_33 ( V_61 ,
& V_54 -> V_55 ) ;
if ( V_27 ) {
F_31 ( V_54 ) ;
V_54 = NULL ;
}
F_13 ( V_19 ) ;
return V_54 ;
}
static int T_7 F_34 ( void )
{
int V_30 , V_31 ;
if ( V_35 )
return 0 ;
V_62 = F_35 ( L_5 , V_63 ) ;
if ( ! V_62 )
return 0 ;
V_61 = F_35 ( L_6 , V_62 ) ;
if ( ! V_61 ) {
F_36 ( V_62 ) ;
return 0 ;
}
F_29 ( V_20 ) ;
V_30 = F_18 ( V_21 , T_3 ) ;
for ( V_31 = 0 ; V_31 < V_30 ; V_31 ++ )
F_29 ( V_21 -> V_32 [ V_31 ] ) ;
F_37 () ;
F_38 ( V_62 , V_64 ) ;
F_38 ( V_61 , V_64 ) ;
F_8 ( L_7 ) ;
return 0 ;
}
void T_7 F_39 ( void )
{
if ( ! V_65 )
F_40 () ;
if ( V_35 )
return;
F_8 ( L_8 ) ;
if ( F_24 () || F_22 () || F_41 () )
F_40 () ;
return;
}
void T_7 F_42 ( void )
{
int V_17 ;
if ( V_35 )
return;
V_17 = V_21 -> V_8 . V_10 ;
F_4 ( V_21 , sizeof( struct V_37 ) ) ;
V_3 = 1 ;
V_21 = F_1 ( V_20 , V_17 ) ;
F_43 () ;
}
