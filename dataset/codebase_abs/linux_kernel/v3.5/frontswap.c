static inline void F_1 ( void ) {
V_1 ++ ;
}
static inline void F_2 ( void ) {
V_2 ++ ;
}
static inline void F_3 ( void ) {
V_3 ++ ;
}
static inline void F_4 ( void ) {
V_4 ++ ;
}
static inline void F_1 ( void ) { }
static inline void F_2 ( void ) { }
static inline void F_3 ( void ) { }
static inline void F_4 ( void ) { }
struct V_5 F_5 ( struct V_5 * V_6 )
{
struct V_5 V_7 = V_5 ;
V_5 = * V_6 ;
V_8 = true ;
return V_7 ;
}
void F_6 ( bool V_9 )
{
V_10 = V_9 ;
}
void F_7 ( unsigned type )
{
struct V_11 * V_12 = V_13 [ type ] ;
F_8 ( V_12 == NULL ) ;
if ( V_12 -> V_14 == NULL )
return;
if ( V_8 )
(* V_5 . V_15 )( type ) ;
}
int F_9 ( struct V_16 * V_16 )
{
int V_17 = - 1 , V_18 = 0 ;
T_1 V_19 = { . V_20 = F_10 ( V_16 ) , } ;
int type = F_11 ( V_19 ) ;
struct V_11 * V_12 = V_13 [ type ] ;
T_2 V_21 = F_12 ( V_19 ) ;
F_8 ( ! F_13 ( V_16 ) ) ;
F_8 ( V_12 == NULL ) ;
if ( F_14 ( V_12 , V_21 ) )
V_18 = 1 ;
V_17 = (* V_5 . V_22 )( type , V_21 , V_16 ) ;
if ( V_17 == 0 ) {
F_15 ( V_12 , V_21 ) ;
F_2 () ;
if ( ! V_18 )
F_16 ( & V_12 -> V_23 ) ;
} else if ( V_18 ) {
F_17 ( V_12 , V_21 ) ;
F_18 ( & V_12 -> V_23 ) ;
F_3 () ;
} else
F_3 () ;
if ( V_10 )
V_17 = - 1 ;
return V_17 ;
}
int F_19 ( struct V_16 * V_16 )
{
int V_17 = - 1 ;
T_1 V_19 = { . V_20 = F_10 ( V_16 ) , } ;
int type = F_11 ( V_19 ) ;
struct V_11 * V_12 = V_13 [ type ] ;
T_2 V_21 = F_12 ( V_19 ) ;
F_8 ( ! F_13 ( V_16 ) ) ;
F_8 ( V_12 == NULL ) ;
if ( F_14 ( V_12 , V_21 ) )
V_17 = (* V_5 . V_24 )( type , V_21 , V_16 ) ;
if ( V_17 == 0 )
F_1 () ;
return V_17 ;
}
void F_20 ( unsigned type , T_2 V_21 )
{
struct V_11 * V_12 = V_13 [ type ] ;
F_8 ( V_12 == NULL ) ;
if ( F_14 ( V_12 , V_21 ) ) {
(* V_5 . V_25 )( type , V_21 ) ;
F_18 ( & V_12 -> V_23 ) ;
F_17 ( V_12 , V_21 ) ;
F_4 () ;
}
}
void F_21 ( unsigned type )
{
struct V_11 * V_12 = V_13 [ type ] ;
F_8 ( V_12 == NULL ) ;
if ( V_12 -> V_14 == NULL )
return;
(* V_5 . V_26 )( type ) ;
F_22 ( & V_12 -> V_23 , 0 ) ;
memset ( V_12 -> V_14 , 0 , V_12 -> V_27 / sizeof( long ) ) ;
}
void F_23 ( unsigned long V_28 )
{
struct V_11 * V_29 = NULL ;
int V_30 ;
unsigned long V_31 = 0 , V_32 ;
unsigned long V_33 = 0 , V_34 = 0 ;
int type ;
bool V_35 = false ;
F_24 ( & V_36 ) ;
V_35 = true ;
V_31 = 0 ;
for ( type = V_37 . V_38 ; type >= 0 ; type = V_29 -> V_39 ) {
V_29 = V_13 [ type ] ;
V_31 += F_25 ( & V_29 -> V_23 ) ;
}
if ( V_31 <= V_28 )
goto V_40;
V_32 = V_31 - V_28 ;
for ( type = V_37 . V_38 ; type >= 0 ; type = V_29 -> V_39 ) {
V_29 = V_13 [ type ] ;
V_30 = F_25 ( & V_29 -> V_23 ) ;
if ( V_32 < V_30 )
V_33 = V_34 = V_32 ;
else {
V_33 = V_30 ;
V_34 = 0 ;
}
if ( F_26 ( V_41 -> V_42 , V_33 ) )
continue;
F_27 ( V_33 ) ;
break;
}
if ( type < 0 )
goto V_40;
V_35 = false ;
F_28 ( & V_36 ) ;
F_29 ( type , true , V_34 ) ;
V_40:
if ( V_35 )
F_28 ( & V_36 ) ;
return;
}
unsigned long F_30 ( void )
{
int type ;
unsigned long V_43 = 0 ;
struct V_11 * V_29 = NULL ;
F_24 ( & V_36 ) ;
for ( type = V_37 . V_38 ; type >= 0 ; type = V_29 -> V_39 ) {
V_29 = V_13 [ type ] ;
V_43 += F_25 ( & V_29 -> V_23 ) ;
}
F_28 ( & V_36 ) ;
return V_43 ;
}
static int T_3 F_31 ( void )
{
#ifdef F_32
struct V_44 * V_45 = F_33 ( L_1 , NULL ) ;
if ( V_45 == NULL )
return - V_46 ;
F_34 ( L_2 , V_47 , V_45 , & V_1 ) ;
F_34 ( L_3 , V_47 , V_45 , & V_2 ) ;
F_34 ( L_4 , V_47 , V_45 ,
& V_3 ) ;
F_34 ( L_5 , V_47 ,
V_45 , & V_4 ) ;
#endif
return 0 ;
}
