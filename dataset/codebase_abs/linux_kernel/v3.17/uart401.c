static int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_3 ) ;
}
static void F_3 ( struct V_1 * V_2 , unsigned char V_4 )
{
F_4 ( ( V_4 ) , V_5 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
return F_2 ( V_6 ) ;
}
static void F_6 ( struct V_1 * V_2 , unsigned char V_7 )
{
F_4 ( ( V_7 ) , V_6 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
int V_8 = 30000 ;
while ( F_8 ( V_2 ) && -- V_8 )
{
unsigned char V_9 = F_5 ( V_2 ) ;
if ( V_9 == V_10 )
V_2 -> V_11 = V_9 ;
else if ( V_2 -> V_12 & V_13 && V_2 -> V_14 )
V_2 -> V_14 ( V_2 -> V_15 , V_9 ) ;
}
if( V_8 == 0 )
F_9 ( V_16 L_1 , V_2 -> V_17 ) ;
}
T_1 F_10 ( int V_18 , void * V_19 )
{
struct V_1 * V_2 = V_19 ;
if ( V_2 == NULL )
{
F_9 ( V_20 L_2 ) ;
return V_21 ;
}
if ( F_8 ( V_2 ) )
F_7 ( V_2 ) ;
return V_22 ;
}
static int
F_11 ( int V_23 , int V_24 ,
void (* F_12) ( int V_23 , unsigned char V_25 ) ,
void (* F_13) ( int V_23 )
)
{
struct V_1 * V_2 = (struct V_1 * )
V_26 [ V_23 ] -> V_2 ;
if ( V_2 -> V_12 )
return - V_27 ;
while ( F_8 ( V_2 ) )
F_5 ( V_2 ) ;
V_2 -> V_14 = F_12 ;
V_2 -> V_12 = V_24 ;
F_14 ( V_2 ) ;
V_2 -> V_28 = 0 ;
return 0 ;
}
static void F_15 ( int V_23 )
{
struct V_1 * V_2 = (struct V_1 * )
V_26 [ V_23 ] -> V_2 ;
F_16 ( V_2 ) ;
V_2 -> V_12 = 0 ;
}
static int F_17 ( int V_23 , unsigned char V_29 )
{
int V_30 ;
unsigned long V_31 ;
struct V_1 * V_2 = (struct V_1 * )
V_26 [ V_23 ] -> V_2 ;
if ( V_2 -> V_28 )
return 1 ;
F_18 ( & V_2 -> V_32 , V_31 ) ;
if ( F_8 ( V_2 ) )
F_7 ( V_2 ) ;
F_19 ( & V_2 -> V_32 , V_31 ) ;
for ( V_30 = 30000 ; V_30 > 0 && ! F_20 ( V_2 ) ; V_30 -- ) ;
if ( ! F_20 ( V_2 ) )
{
F_9 ( V_16 L_3 ) ;
V_2 -> V_28 = 1 ;
F_16 ( V_2 ) ;
F_14 ( V_2 ) ;
return 1 ;
}
F_6 ( V_2 , V_29 ) ;
return 1 ;
}
static inline int F_21 ( int V_23 )
{
return 0 ;
}
static inline int F_22 ( int V_23 )
{
return 0 ;
}
static inline void F_23 ( int V_23 )
{
}
static inline int F_24 ( int V_23 )
{
return 0 ;
}
static void F_14 ( struct V_1 * V_2 )
{
int V_33 , V_30 ;
unsigned long V_31 ;
F_18 ( & V_2 -> V_32 , V_31 ) ;
for ( V_30 = 30000 ; V_30 > 0 && ! F_20 ( V_2 ) ; V_30 -- ) ;
V_2 -> V_11 = 0 ;
F_3 ( V_2 , V_34 ) ;
V_33 = 0 ;
for ( V_30 = 50000 ; V_30 > 0 && ! V_33 ; V_30 -- )
if ( V_2 -> V_11 == V_10 )
V_33 = 1 ;
else if ( F_8 ( V_2 ) )
if ( F_5 ( V_2 ) == V_10 )
V_33 = 1 ;
F_19 ( & V_2 -> V_32 , V_31 ) ;
}
static int F_16 ( struct V_1 * V_2 )
{
int V_33 , V_30 , V_35 ;
V_33 = 0 ;
for ( V_35 = 0 ; V_35 < 2 && ! V_33 ; V_35 ++ )
{
for ( V_30 = 30000 ; V_30 > 0 && ! F_20 ( V_2 ) ; V_30 -- ) ;
V_2 -> V_11 = 0 ;
F_3 ( V_2 , V_36 ) ;
for ( V_30 = 50000 ; V_30 > 0 && ! V_33 ; V_30 -- )
{
if ( V_2 -> V_11 == V_10 )
V_33 = 1 ;
else if ( F_8 ( V_2 ) )
{
if ( F_5 ( V_2 ) == V_10 )
V_33 = 1 ;
}
}
}
if ( V_33 )
F_7 ( V_2 ) ;
else
F_25 ( F_9 ( L_4 ) ) ;
return V_33 ;
}
int F_26 ( struct V_37 * V_38 , struct V_39 * V_40 )
{
struct V_1 * V_2 ;
char * V_41 = L_5 ;
int V_33 = 0 ;
unsigned long V_31 ;
F_25 ( F_9 ( L_6 ) ) ;
V_38 -> V_42 [ 4 ] = - 1 ;
if ( ! F_27 ( V_38 -> V_43 , 4 , L_7 ) ) {
F_9 ( V_44 L_8 , V_38 -> V_43 ) ;
return 0 ;
}
V_2 = F_28 ( sizeof( struct V_1 ) , V_45 ) ;
if ( ! V_2 ) {
F_9 ( V_16 L_9 ) ;
goto V_46;
}
V_2 -> V_17 = V_38 -> V_43 ;
V_2 -> V_18 = V_38 -> V_18 ;
V_2 -> V_47 = V_38 -> V_47 ;
V_2 -> V_14 = NULL ;
V_2 -> V_12 = 0 ;
V_2 -> V_11 = 0 ;
V_2 -> V_15 = 0 ;
V_2 -> V_48 = 0 ;
F_29 ( & V_2 -> V_32 ) ;
F_18 ( & V_2 -> V_32 , V_31 ) ;
V_33 = F_16 ( V_2 ) ;
F_19 ( & V_2 -> V_32 , V_31 ) ;
if ( ! V_33 )
goto V_49;
if ( V_38 -> V_41 )
V_41 = V_38 -> V_41 ;
if ( V_2 -> V_18 < 0 ) {
V_2 -> V_48 = 1 ;
V_2 -> V_18 *= - 1 ;
} else
V_2 -> V_48 = 0 ;
if ( ! V_2 -> V_48 )
if ( F_30 ( V_2 -> V_18 , F_10 , 0 , L_7 , V_2 ) < 0 ) {
F_9 ( V_16 L_10 , V_2 -> V_18 ) ;
V_2 -> V_48 = 1 ;
}
V_2 -> V_15 = F_31 () ;
F_14 ( V_2 ) ;
if ( V_2 -> V_15 == - 1 ) {
F_9 ( V_44 L_11 ) ;
goto V_50;
}
F_32 ( V_41 , V_38 ) ;
V_26 [ V_2 -> V_15 ] = F_33 ( & V_51 ,
sizeof( struct V_52 ) ,
V_45 ) ;
if ( ! V_26 [ V_2 -> V_15 ] ) {
F_9 ( V_20 L_12 ) ;
goto V_53;
}
if ( V_40 )
V_26 [ V_2 -> V_15 ] -> V_40 = V_40 ;
V_26 [ V_2 -> V_15 ] -> V_2 = V_2 ;
V_26 [ V_2 -> V_15 ] -> V_54 = F_33 ( & V_55 ,
sizeof( struct V_56 ) ,
V_45 ) ;
if ( ! V_26 [ V_2 -> V_15 ] -> V_54 ) {
F_9 ( V_16 L_12 ) ;
goto V_57;
}
strcpy ( V_26 [ V_2 -> V_15 ] -> V_58 . V_41 , V_41 ) ;
V_26 [ V_2 -> V_15 ] -> V_54 -> V_59 = L_13 ;
V_26 [ V_2 -> V_15 ] -> V_54 -> V_60 = V_2 -> V_15 ;
if ( V_40 )
V_26 [ V_2 -> V_15 ] -> V_54 -> V_40 = V_40 ;
V_38 -> V_42 [ 4 ] = V_2 -> V_15 ;
F_34 () ;
V_2 -> V_12 = 0 ;
return 1 ;
V_57:
F_35 ( V_26 [ V_2 -> V_15 ] ) ;
V_53:
F_36 ( V_2 -> V_15 ) ;
V_50:
if ( ! V_2 -> V_48 )
F_37 ( V_2 -> V_18 , V_2 ) ;
V_49:
F_35 ( V_2 ) ;
V_46:
F_38 ( V_38 -> V_43 , 4 ) ;
return 0 ;
}
void F_39 ( struct V_37 * V_38 )
{
struct V_1 * V_2 ;
int V_35 = V_38 -> V_42 [ 4 ] ;
if( V_35 == - 1 || V_26 [ V_35 ] == NULL )
return;
V_2 = V_26 [ V_38 -> V_42 [ 4 ] ] -> V_2 ;
if ( V_2 == NULL )
return;
F_16 ( V_2 ) ;
F_38 ( V_38 -> V_43 , 4 ) ;
if ( ! V_2 -> V_48 )
F_37 ( V_2 -> V_18 , V_2 ) ;
if ( V_2 )
{
F_35 ( V_26 [ V_2 -> V_15 ] -> V_54 ) ;
F_35 ( V_26 [ V_2 -> V_15 ] ) ;
F_35 ( V_2 ) ;
V_2 = NULL ;
}
F_36 ( V_38 -> V_42 [ 4 ] ) ;
}
static int T_2 F_40 ( void )
{
V_61 . V_18 = V_18 ;
V_61 . V_43 = V_62 ;
if ( V_61 . V_43 != - 1 && V_61 . V_18 != - 1 ) {
F_9 ( V_44 L_14 ) ;
if ( ! F_26 ( & V_61 , V_63 ) )
return - V_64 ;
}
return 0 ;
}
static void T_3 F_41 ( void )
{
if ( V_61 . V_43 != - 1 && V_61 . V_18 != - 1 )
F_39 ( & V_61 ) ;
}
static int T_2 F_42 ( char * V_65 )
{
int V_66 [ 3 ] ;
V_65 = F_43 ( V_65 , F_44 ( V_66 ) , V_66 ) ;
V_62 = V_66 [ 1 ] ;
V_18 = V_66 [ 2 ] ;
return 1 ;
}
