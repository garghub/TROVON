static inline void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
#ifdef F_2
V_2 -> V_5 = V_4 ;
#endif
}
static int F_3 ( struct V_6 * V_7 , void * V_8 )
{
struct V_9 * V_10 = V_7 -> V_11 ;
F_4 ( V_7 , V_10 -> V_12 , V_10 -> V_13 ) ;
return 0 ;
}
static int F_5 ( struct V_14 * V_14 , struct V_15 * V_15 )
{
return F_6 ( V_15 , F_3 , F_7 ( V_14 ) -> V_16 ) ;
}
static struct V_3 *
F_8 ( struct V_3 * V_4 , struct V_9 * V_10 ,
const char * V_17 )
{
struct V_3 * V_18 ;
V_18 = F_9 ( V_17 ,
strncmp ( V_17 , L_1 , 9 ) ? V_19 : V_20 ,
V_4 , & V_21 , V_10 ) ;
if ( V_18 == NULL )
return NULL ;
if ( ! strncmp ( V_17 , L_1 , 9 ) )
V_18 -> V_22 = 0 ;
else
V_18 -> V_22 = V_10 -> V_13 ;
return V_18 ;
}
void F_10 ( struct V_3 * V_5 , struct V_9 * V_23 )
{
F_8 ( V_5 , V_23 , V_23 -> V_17 ) ;
}
void F_11 ( struct V_3 * V_5 ,
struct V_9 * V_23 )
{
F_12 ( V_23 -> V_17 , V_5 ) ;
}
void F_13 ( struct V_3 * V_5 ,
struct V_9 * V_24 ,
struct V_9 * V_25 )
{
struct V_3 * V_18 ;
if ( ! V_25 ) {
F_10 ( V_5 , V_24 ) ;
return;
}
for ( V_18 = V_5 -> V_26 ; V_18 != NULL ; V_18 = V_18 -> V_27 )
if ( V_18 -> V_16 == V_25 )
break;
if ( V_18 == NULL ) {
F_14 ( V_28 L_2
L_3 , V_25 -> V_17 ) ;
} else {
V_18 -> V_16 = V_24 ;
V_18 -> V_22 = V_24 -> V_13 ;
}
}
static int F_15 ( struct V_3 * V_4 , const char * V_17 )
{
struct V_3 * V_18 ;
int V_29 = 0 ;
F_16 ( & V_30 ) ;
for ( V_18 = V_4 -> V_26 ; V_18 != NULL ; V_18 = V_18 -> V_27 ) {
if ( strcmp ( V_18 -> V_17 , V_17 ) == 0 ) {
V_29 = 1 ;
break;
}
}
F_17 ( & V_30 ) ;
return V_29 ;
}
static const char * F_18 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_17 )
{
char * V_31 ;
int V_32 = strlen ( V_17 ) + 2 + 1 ;
int V_33 = 1 , V_22 ;
realloc:
V_31 = F_19 ( V_32 , V_34 ) ;
if ( V_31 == NULL ) {
F_14 ( V_35 L_4
L_5 , V_17 ) ;
return V_17 ;
}
V_36:
V_22 = snprintf ( V_31 , V_32 , L_6 , V_17 , V_33 ) ;
V_22 ++ ;
if ( V_22 > V_32 ) {
F_20 ( V_31 ) ;
V_32 = V_22 ;
goto realloc;
}
if ( F_15 ( V_4 , V_31 ) ) {
V_33 ++ ;
goto V_36;
}
F_14 ( V_28 L_7
L_8 , V_2 -> V_37 , V_31 ) ;
return V_31 ;
}
void F_21 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_9 * V_10 ;
struct V_3 * V_18 ;
struct V_1 * V_38 ;
const char * V_39 ;
F_1 ( V_2 , V_4 ) ;
for ( V_38 = NULL ; ( V_38 = F_22 ( V_2 , V_38 ) ) ; ) {
V_39 = strrchr ( V_38 -> V_37 , '/' ) ;
if ( ! V_39 )
V_39 = V_38 -> V_37 ;
else
++ V_39 ;
if ( F_15 ( V_4 , V_39 ) )
V_39 = F_18 ( V_2 , V_4 , V_39 ) ;
V_18 = F_23 ( V_39 , V_4 ) ;
if ( V_18 == NULL )
break;
F_21 ( V_38 , V_18 ) ;
}
F_24 ( V_38 ) ;
for ( V_10 = V_2 -> V_40 ; V_10 != NULL ; V_10 = V_10 -> V_27 ) {
V_39 = V_10 -> V_17 ;
if ( strchr ( V_39 , '/' ) )
continue;
if ( F_15 ( V_4 , V_39 ) )
V_39 = F_18 ( V_2 , V_4 , V_39 ) ;
V_18 = F_8 ( V_4 , V_10 , V_39 ) ;
if ( V_18 == NULL )
break;
}
}
void T_1 F_25 ( void )
{
struct V_1 * V_41 ;
V_42 = F_23 ( L_9 , NULL ) ;
if ( V_42 == NULL )
return;
V_41 = F_26 ( L_10 ) ;
if ( V_41 == NULL ) {
F_27 ( L_11 ) ;
return;
}
F_21 ( V_41 , V_42 ) ;
F_24 ( V_41 ) ;
}
