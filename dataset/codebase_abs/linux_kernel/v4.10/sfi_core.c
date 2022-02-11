static void T_1 * T_2 F_1 ( T_3 V_1 , T_4 V_2 )
{
if ( ! V_1 || ! V_2 )
return NULL ;
if ( V_3 )
return F_2 ( V_1 , V_2 ) ;
else
return F_3 ( V_1 , V_2 ) ;
}
static void T_2 F_4 ( void T_1 * V_4 , T_4 V_2 )
{
if ( ! V_4 || ! V_2 )
return;
if ( V_3 )
F_5 ( V_4 ) ;
else
F_6 ( V_4 , V_2 ) ;
}
static void F_7 ( unsigned long long V_5 ,
struct V_6 * V_7 )
{
F_8 ( L_1 ,
V_7 -> V_8 , V_5 ,
V_7 -> V_9 , V_7 -> V_10 , V_7 -> V_11 ,
V_7 -> V_12 ) ;
}
static int F_9 ( struct V_6 * V_13 )
{
T_5 V_14 = 0 ;
T_5 * V_15 = ( T_5 * ) V_13 ;
T_4 V_16 = V_13 -> V_9 ;
if ( V_16 > 0x100000 ) {
F_10 ( L_2 , V_16 ) ;
return - 1 ;
}
while ( V_16 -- )
V_14 += * V_15 ++ ;
if ( V_14 ) {
F_10 ( L_3 ,
V_13 -> V_17 , V_13 -> V_17 - V_14 ) ;
return - 1 ;
}
return 0 ;
}
static struct V_6 * F_11 ( T_3 V_5 )
{
struct V_6 * V_18 ;
T_4 V_16 ;
if ( ! F_12 ( V_19 , V_5 , sizeof( struct V_6 ) ) )
V_18 = F_1 ( V_5 , sizeof( struct V_6 ) ) ;
else
V_18 = ( void * ) V_20 + ( V_5 - V_19 ) ;
if ( F_12 ( V_18 , V_18 , V_18 -> V_9 ) )
return V_18 ;
V_16 = V_18 -> V_9 ;
if ( ! F_12 ( V_19 , V_5 , sizeof( struct V_6 ) ) )
F_4 ( V_18 , sizeof( struct V_6 ) ) ;
return F_1 ( V_5 , V_16 ) ;
}
static void F_13 ( struct V_6 * V_18 )
{
if ( ! F_12 ( V_20 , V_18 , V_18 -> V_9 ) )
F_4 ( V_18 , F_12 ( V_18 , V_18 , V_18 -> V_9 ) ?
sizeof( * V_18 ) : V_18 -> V_9 ) ;
}
static int F_14 ( struct V_6 * V_18 ,
struct V_21 * V_22 )
{
if ( strncmp ( V_18 -> V_8 , V_22 -> V_8 , V_23 )
|| ( V_22 -> V_11 && strncmp ( V_18 -> V_11 ,
V_22 -> V_11 , V_24 ) )
|| ( V_22 -> V_12 && strncmp ( V_18 -> V_12 ,
V_22 -> V_12 , V_25 ) ) )
return - 1 ;
return 0 ;
}
struct V_6 *
T_2 F_15 ( T_3 V_5 , struct V_21 * V_22 )
{
struct V_6 * V_18 ;
void * V_26 = NULL ;
V_18 = F_11 ( V_5 ) ;
if ( ! V_18 )
return F_16 ( - V_27 ) ;
if ( ! V_22 -> V_8 ) {
F_7 ( V_5 , V_18 ) ;
if ( F_9 ( V_18 ) )
V_26 = F_16 ( - V_28 ) ;
} else {
if ( ! F_14 ( V_18 , V_22 ) )
return V_18 ;
}
F_13 ( V_18 ) ;
return V_26 ;
}
struct V_6 * F_17 ( struct V_21 * V_22 )
{
struct V_6 * V_18 ;
T_4 V_29 , V_30 ;
V_29 = F_18 ( V_20 , T_3 ) ;
for ( V_30 = 0 ; V_30 < V_29 ; V_30 ++ ) {
V_18 = F_15 ( V_20 -> V_31 [ V_30 ] , V_22 ) ;
if ( ! F_19 ( V_18 ) && V_18 )
return V_18 ;
}
return NULL ;
}
void F_20 ( struct V_6 * V_18 )
{
F_13 ( V_18 ) ;
}
int F_21 ( char * V_32 , char * V_11 , char * V_12 ,
T_6 V_33 )
{
struct V_6 * V_13 = NULL ;
struct V_21 V_22 ;
int V_26 = - V_28 ;
if ( V_34 || ! V_33 || ! V_32 )
goto exit;
V_22 . V_8 = V_32 ;
V_22 . V_11 = V_11 ;
V_22 . V_12 = V_12 ;
V_13 = F_17 ( & V_22 ) ;
if ( ! V_13 )
goto exit;
V_26 = V_33 ( V_13 ) ;
F_20 ( V_13 ) ;
exit:
return V_26 ;
}
static int T_7 F_22 ( void )
{
struct V_21 V_22 = V_35 ;
int V_29 , V_30 ;
void * V_26 ;
V_20 = F_1 ( V_19 , sizeof( struct V_36 ) ) ;
if ( ! V_20 )
return - V_27 ;
V_29 = F_18 ( V_20 , T_3 ) ;
for ( V_30 = 0 ; V_30 < V_29 ; V_30 ++ ) {
V_26 = F_15 ( V_20 -> V_31 [ V_30 ] , & V_22 ) ;
if ( F_19 ( V_26 ) )
return F_23 ( V_26 ) ;
}
return 0 ;
}
static T_7 int F_24 ( void )
{
unsigned long V_37 , V_9 ;
void * V_38 ;
V_9 = V_39 - V_40 ;
V_38 = F_1 ( V_40 , V_9 ) ;
if ( ! V_38 )
return - 1 ;
for ( V_37 = 0 ; V_37 < V_9 ; V_37 += 16 ) {
struct V_6 * V_41 ;
V_41 = V_38 + V_37 ;
if ( strncmp ( V_41 -> V_8 , V_42 ,
V_23 ) )
continue;
if ( V_41 -> V_9 > V_43 )
continue;
F_7 ( V_40 + V_37 ,
V_41 ) ;
if ( F_9 ( V_41 ) )
continue;
if ( ! F_25 ( V_19 , V_19 + V_41 -> V_9 ) ) {
F_8 ( L_4 ,
V_19 , V_41 -> V_9 ) ;
continue;
}
V_19 = V_40 + V_37 ;
F_4 ( V_38 , V_9 ) ;
return 0 ;
}
F_4 ( V_38 , V_9 ) ;
return - 1 ;
}
static T_8 F_26 ( struct V_44 * V_45 , struct V_46 * V_47 ,
struct V_48 * V_49 , char * V_50 ,
T_9 V_37 , T_10 V_51 )
{
struct V_52 * V_53 =
F_27 ( V_49 , struct V_52 , V_54 ) ;
struct V_6 * V_18 = NULL ;
struct V_21 V_22 ;
T_8 V_55 ;
V_22 . V_8 = V_53 -> V_56 ;
V_22 . V_11 = NULL ;
V_22 . V_12 = NULL ;
if ( strncmp ( V_42 , V_53 -> V_56 , V_23 ) ) {
V_18 = F_17 ( & V_22 ) ;
if ( ! V_18 )
return 0 ;
V_55 = F_28 ( V_50 , V_51 , & V_37 ,
V_18 , V_18 -> V_9 ) ;
F_20 ( V_18 ) ;
} else
V_55 = F_28 ( V_50 , V_51 , & V_37 ,
V_20 , V_20 -> V_7 . V_9 ) ;
return V_55 ;
}
struct V_52 T_7 * F_29 ( T_3 V_5 )
{
struct V_52 * V_53 ;
struct V_6 * V_18 ;
int V_26 ;
V_53 = F_30 ( sizeof( struct V_52 ) , V_57 ) ;
if ( ! V_53 )
return NULL ;
V_18 = F_11 ( V_5 ) ;
if ( ! V_18 || ! V_18 -> V_8 [ 0 ] ) {
F_31 ( V_53 ) ;
return NULL ;
}
F_32 ( & V_53 -> V_54 . V_54 ) ;
memcpy ( V_53 -> V_56 , V_18 -> V_8 , V_23 ) ;
V_53 -> V_54 . V_2 = 0 ;
V_53 -> V_54 . V_58 = F_26 ;
V_53 -> V_54 . V_54 . V_56 = V_53 -> V_56 ;
V_53 -> V_54 . V_54 . V_59 = 0400 ;
V_26 = F_33 ( V_60 ,
& V_53 -> V_54 ) ;
if ( V_26 ) {
F_31 ( V_53 ) ;
V_53 = NULL ;
}
F_13 ( V_18 ) ;
return V_53 ;
}
static int T_7 F_34 ( void )
{
int V_29 , V_30 ;
if ( V_34 )
return 0 ;
V_61 = F_35 ( L_5 , V_62 ) ;
if ( ! V_61 )
return 0 ;
V_60 = F_35 ( L_6 , V_61 ) ;
if ( ! V_60 ) {
F_36 ( V_61 ) ;
return 0 ;
}
F_29 ( V_19 ) ;
V_29 = F_18 ( V_20 , T_3 ) ;
for ( V_30 = 0 ; V_30 < V_29 ; V_30 ++ )
F_29 ( V_20 -> V_31 [ V_30 ] ) ;
F_37 () ;
F_38 ( V_61 , V_63 ) ;
F_38 ( V_60 , V_63 ) ;
F_8 ( L_7 ) ;
return 0 ;
}
void T_7 F_39 ( void )
{
if ( ! V_64 )
F_40 () ;
if ( V_34 )
return;
F_8 ( L_8 ) ;
if ( F_24 () || F_22 () || F_41 () )
F_40 () ;
return;
}
void T_7 F_42 ( void )
{
int V_16 ;
if ( V_34 )
return;
V_16 = V_20 -> V_7 . V_9 ;
F_4 ( V_20 , sizeof( struct V_36 ) ) ;
V_3 = 1 ;
V_20 = F_1 ( V_19 , V_16 ) ;
F_43 () ;
}
