static int F_1 ( T_1 * V_1 )
{
return F_2 ( V_2 ) ;
}
static void F_3 ( T_1 * V_1 , unsigned char V_3 )
{
F_4 ( ( V_3 ) , V_4 ) ;
}
static int F_5 ( T_1 * V_1 )
{
return F_2 ( V_5 ) ;
}
static void F_6 ( T_1 * V_1 , unsigned char V_6 )
{
F_4 ( ( V_6 ) , V_5 ) ;
}
static void F_7 ( T_1 * V_1 )
{
int V_7 = 30000 ;
while ( F_8 ( V_1 ) && -- V_7 )
{
unsigned char V_8 = F_5 ( V_1 ) ;
if ( V_8 == V_9 )
V_1 -> V_10 = V_8 ;
else if ( V_1 -> V_11 & V_12 && V_1 -> V_13 )
V_1 -> V_13 ( V_1 -> V_14 , V_8 ) ;
}
if( V_7 == 0 )
F_9 ( V_15 L_1 , V_1 -> V_16 ) ;
}
T_2 F_10 ( int V_17 , void * V_18 )
{
T_1 * V_1 = V_18 ;
if ( V_1 == NULL )
{
F_9 ( V_19 L_2 ) ;
return V_20 ;
}
if ( F_8 ( V_1 ) )
F_7 ( V_1 ) ;
return V_21 ;
}
static int
F_11 ( int V_22 , int V_23 ,
void (* F_12) ( int V_22 , unsigned char V_24 ) ,
void (* F_13) ( int V_22 )
)
{
T_1 * V_1 = ( T_1 * ) V_25 [ V_22 ] -> V_1 ;
if ( V_1 -> V_11 )
return - V_26 ;
while ( F_8 ( V_1 ) )
F_5 ( V_1 ) ;
V_1 -> V_13 = F_12 ;
V_1 -> V_11 = V_23 ;
F_14 ( V_1 ) ;
V_1 -> V_27 = 0 ;
return 0 ;
}
static void F_15 ( int V_22 )
{
T_1 * V_1 = ( T_1 * ) V_25 [ V_22 ] -> V_1 ;
F_16 ( V_1 ) ;
V_1 -> V_11 = 0 ;
}
static int F_17 ( int V_22 , unsigned char V_28 )
{
int V_29 ;
unsigned long V_30 ;
T_1 * V_1 = ( T_1 * ) V_25 [ V_22 ] -> V_1 ;
if ( V_1 -> V_27 )
return 1 ;
F_18 ( & V_1 -> V_31 , V_30 ) ;
if ( F_8 ( V_1 ) )
F_7 ( V_1 ) ;
F_19 ( & V_1 -> V_31 , V_30 ) ;
for ( V_29 = 30000 ; V_29 > 0 && ! F_20 ( V_1 ) ; V_29 -- ) ;
if ( ! F_20 ( V_1 ) )
{
F_9 ( V_15 L_3 ) ;
V_1 -> V_27 = 1 ;
F_16 ( V_1 ) ;
F_14 ( V_1 ) ;
return 1 ;
}
F_6 ( V_1 , V_28 ) ;
return 1 ;
}
static inline int F_21 ( int V_22 )
{
return 0 ;
}
static inline int F_22 ( int V_22 )
{
return 0 ;
}
static inline void F_23 ( int V_22 )
{
}
static inline int F_24 ( int V_22 )
{
return 0 ;
}
static void F_14 ( T_1 * V_1 )
{
int V_32 , V_29 ;
unsigned long V_30 ;
F_18 ( & V_1 -> V_31 , V_30 ) ;
for ( V_29 = 30000 ; V_29 > 0 && ! F_20 ( V_1 ) ; V_29 -- ) ;
V_1 -> V_10 = 0 ;
F_3 ( V_1 , V_33 ) ;
V_32 = 0 ;
for ( V_29 = 50000 ; V_29 > 0 && ! V_32 ; V_29 -- )
if ( V_1 -> V_10 == V_9 )
V_32 = 1 ;
else if ( F_8 ( V_1 ) )
if ( F_5 ( V_1 ) == V_9 )
V_32 = 1 ;
F_19 ( & V_1 -> V_31 , V_30 ) ;
}
static int F_16 ( T_1 * V_1 )
{
int V_32 , V_29 , V_34 ;
V_32 = 0 ;
for ( V_34 = 0 ; V_34 < 2 && ! V_32 ; V_34 ++ )
{
for ( V_29 = 30000 ; V_29 > 0 && ! F_20 ( V_1 ) ; V_29 -- ) ;
V_1 -> V_10 = 0 ;
F_3 ( V_1 , V_35 ) ;
for ( V_29 = 50000 ; V_29 > 0 && ! V_32 ; V_29 -- )
{
if ( V_1 -> V_10 == V_9 )
V_32 = 1 ;
else if ( F_8 ( V_1 ) )
{
if ( F_5 ( V_1 ) == V_9 )
V_32 = 1 ;
}
}
}
if ( V_32 )
{
F_25 ( F_9 ( L_4 ) ) ;
}
else
F_26 ( F_9 ( L_5 ) ) ;
if ( V_32 )
F_7 ( V_1 ) ;
return V_32 ;
}
int F_27 ( struct V_36 * V_37 , struct V_38 * V_39 )
{
T_1 * V_1 ;
char * V_40 = L_6 ;
int V_32 = 0 ;
unsigned long V_30 ;
F_26 ( F_9 ( L_7 ) ) ;
V_37 -> V_41 [ 4 ] = - 1 ;
if ( ! F_28 ( V_37 -> V_42 , 4 , L_8 ) ) {
F_9 ( V_43 L_9 , V_37 -> V_42 ) ;
return 0 ;
}
V_1 = F_29 ( sizeof( T_1 ) , V_44 ) ;
if ( ! V_1 ) {
F_9 ( V_15 L_10 ) ;
goto V_45;
}
V_1 -> V_16 = V_37 -> V_42 ;
V_1 -> V_17 = V_37 -> V_17 ;
V_1 -> V_46 = V_37 -> V_46 ;
V_1 -> V_13 = NULL ;
V_1 -> V_11 = 0 ;
V_1 -> V_10 = 0 ;
V_1 -> V_14 = 0 ;
V_1 -> V_47 = 0 ;
F_30 ( & V_1 -> V_31 ) ;
F_18 ( & V_1 -> V_31 , V_30 ) ;
V_32 = F_16 ( V_1 ) ;
F_19 ( & V_1 -> V_31 , V_30 ) ;
if ( ! V_32 )
goto V_48;
if ( V_37 -> V_40 )
V_40 = V_37 -> V_40 ;
if ( V_1 -> V_17 < 0 ) {
V_1 -> V_47 = 1 ;
V_1 -> V_17 *= - 1 ;
} else
V_1 -> V_47 = 0 ;
if ( ! V_1 -> V_47 )
if ( F_31 ( V_1 -> V_17 , F_10 , 0 , L_8 , V_1 ) < 0 ) {
F_9 ( V_15 L_11 , V_1 -> V_17 ) ;
V_1 -> V_47 = 1 ;
}
V_1 -> V_14 = F_32 () ;
F_14 ( V_1 ) ;
if ( V_1 -> V_14 == - 1 ) {
F_9 ( V_43 L_12 ) ;
goto V_49;
}
F_33 ( V_40 , V_37 ) ;
V_25 [ V_1 -> V_14 ] = F_34 ( & V_50 ,
sizeof( struct V_51 ) ,
V_44 ) ;
if ( ! V_25 [ V_1 -> V_14 ] ) {
F_9 ( V_19 L_13 ) ;
goto V_52;
}
if ( V_39 )
V_25 [ V_1 -> V_14 ] -> V_39 = V_39 ;
V_25 [ V_1 -> V_14 ] -> V_1 = V_1 ;
V_25 [ V_1 -> V_14 ] -> V_53 = F_34 ( & V_54 ,
sizeof( struct V_55 ) ,
V_44 ) ;
if ( ! V_25 [ V_1 -> V_14 ] -> V_53 ) {
F_9 ( V_15 L_13 ) ;
goto V_56;
}
strcpy ( V_25 [ V_1 -> V_14 ] -> V_57 . V_40 , V_40 ) ;
V_25 [ V_1 -> V_14 ] -> V_53 -> V_58 = L_14 ;
V_25 [ V_1 -> V_14 ] -> V_53 -> V_59 = V_1 -> V_14 ;
if ( V_39 )
V_25 [ V_1 -> V_14 ] -> V_53 -> V_39 = V_39 ;
V_37 -> V_41 [ 4 ] = V_1 -> V_14 ;
F_35 () ;
V_1 -> V_11 = 0 ;
return 1 ;
V_56:
F_36 ( V_25 [ V_1 -> V_14 ] ) ;
V_52:
F_37 ( V_1 -> V_14 ) ;
V_49:
if ( ! V_1 -> V_47 )
F_38 ( V_1 -> V_17 , V_1 ) ;
V_48:
F_36 ( V_1 ) ;
V_45:
F_39 ( V_37 -> V_42 , 4 ) ;
return 0 ;
}
void F_40 ( struct V_36 * V_37 )
{
T_1 * V_1 ;
int V_34 = V_37 -> V_41 [ 4 ] ;
if( V_34 == - 1 || V_25 [ V_34 ] == NULL )
return;
V_1 = V_25 [ V_37 -> V_41 [ 4 ] ] -> V_1 ;
if ( V_1 == NULL )
return;
F_16 ( V_1 ) ;
F_39 ( V_37 -> V_42 , 4 ) ;
if ( ! V_1 -> V_47 )
F_38 ( V_1 -> V_17 , V_1 ) ;
if ( V_1 )
{
F_36 ( V_25 [ V_1 -> V_14 ] -> V_53 ) ;
F_36 ( V_25 [ V_1 -> V_14 ] ) ;
F_36 ( V_1 ) ;
V_1 = NULL ;
}
F_37 ( V_37 -> V_41 [ 4 ] ) ;
}
static int T_3 F_41 ( void )
{
V_60 . V_17 = V_17 ;
V_60 . V_42 = V_61 ;
if ( V_60 . V_42 != - 1 && V_60 . V_17 != - 1 ) {
F_9 ( V_43 L_15 ) ;
if ( ! F_27 ( & V_60 , V_62 ) )
return - V_63 ;
}
return 0 ;
}
static void T_4 F_42 ( void )
{
if ( V_60 . V_42 != - 1 && V_60 . V_17 != - 1 )
F_40 ( & V_60 ) ;
}
static int T_3 F_43 ( char * V_64 )
{
int V_65 [ 3 ] ;
V_64 = F_44 ( V_64 , F_45 ( V_65 ) , V_65 ) ;
V_61 = V_65 [ 1 ] ;
V_17 = V_65 [ 2 ] ;
return 1 ;
}
