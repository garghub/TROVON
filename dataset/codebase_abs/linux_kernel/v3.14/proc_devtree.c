static inline void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
V_2 -> V_5 = V_4 ;
}
static int F_2 ( struct V_6 * V_7 , void * V_8 )
{
struct V_9 * V_10 = V_7 -> V_11 ;
F_3 ( V_7 , V_10 -> V_12 , V_10 -> V_13 ) ;
return 0 ;
}
static int F_4 ( struct V_14 * V_14 , struct V_15 * V_15 )
{
return F_5 ( V_15 , F_2 , F_6 ( V_14 ) ) ;
}
static struct V_3 *
F_7 ( struct V_3 * V_4 , struct V_9 * V_10 ,
const char * V_16 )
{
struct V_3 * V_17 ;
V_17 = F_8 ( V_16 ,
strncmp ( V_16 , L_1 , 9 ) ? V_18 : V_19 ,
V_4 , & V_20 , V_10 ) ;
if ( V_17 == NULL )
return NULL ;
if ( ! strncmp ( V_16 , L_1 , 9 ) )
F_9 ( V_17 , 0 ) ;
else
F_9 ( V_17 , V_10 -> V_13 ) ;
return V_17 ;
}
void F_10 ( struct V_3 * V_5 , struct V_9 * V_21 )
{
F_7 ( V_5 , V_21 , V_21 -> V_16 ) ;
}
void F_11 ( struct V_3 * V_5 ,
struct V_9 * V_21 )
{
F_12 ( V_21 -> V_16 , V_5 ) ;
}
void F_13 ( struct V_3 * V_5 ,
struct V_9 * V_22 ,
struct V_9 * V_23 )
{
struct V_3 * V_17 ;
if ( ! V_23 ) {
F_10 ( V_5 , V_22 ) ;
return;
}
for ( V_17 = V_5 -> V_24 ; V_17 != NULL ; V_17 = V_17 -> V_25 )
if ( V_17 -> V_26 == V_23 )
break;
if ( V_17 == NULL ) {
F_14 ( L_2 ,
V_23 -> V_16 ) ;
} else {
V_17 -> V_26 = V_22 ;
V_17 -> V_27 = V_22 -> V_13 ;
}
}
static int F_15 ( struct V_3 * V_4 , const char * V_16 )
{
struct V_3 * V_17 ;
int V_28 = 0 ;
F_16 ( & V_29 ) ;
for ( V_17 = V_4 -> V_24 ; V_17 != NULL ; V_17 = V_17 -> V_25 ) {
if ( strcmp ( V_17 -> V_16 , V_16 ) == 0 ) {
V_28 = 1 ;
break;
}
}
F_17 ( & V_29 ) ;
return V_28 ;
}
static const char * F_18 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_16 )
{
char * V_30 ;
int V_31 = strlen ( V_16 ) + 2 + 1 ;
int V_32 = 1 , V_27 ;
realloc:
V_30 = F_19 ( V_31 , V_33 ) ;
if ( V_30 == NULL ) {
F_20 ( L_3
L_4 , V_16 ) ;
return V_16 ;
}
V_34:
V_27 = snprintf ( V_30 , V_31 , L_5 , V_16 , V_32 ) ;
V_27 ++ ;
if ( V_27 > V_31 ) {
F_21 ( V_30 ) ;
V_31 = V_27 ;
goto realloc;
}
if ( F_15 ( V_4 , V_30 ) ) {
V_32 ++ ;
goto V_34;
}
F_14 ( L_6 ,
V_2 -> V_35 , V_30 ) ;
return V_30 ;
}
void F_22 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_9 * V_10 ;
struct V_3 * V_17 ;
struct V_1 * V_36 ;
const char * V_37 ;
F_1 ( V_2 , V_4 ) ;
for ( V_36 = NULL ; ( V_36 = F_23 ( V_2 , V_36 ) ) ; ) {
V_37 = F_24 ( V_36 -> V_35 ) ;
if ( F_15 ( V_4 , V_37 ) )
V_37 = F_18 ( V_2 , V_4 , V_37 ) ;
V_17 = F_25 ( V_37 , V_4 ) ;
if ( V_17 == NULL )
break;
F_22 ( V_36 , V_17 ) ;
}
F_26 ( V_36 ) ;
for ( V_10 = V_2 -> V_38 ; V_10 != NULL ; V_10 = V_10 -> V_25 ) {
V_37 = V_10 -> V_16 ;
if ( strchr ( V_37 , '/' ) )
continue;
if ( F_15 ( V_4 , V_37 ) )
V_37 = F_18 ( V_2 , V_4 , V_37 ) ;
V_17 = F_7 ( V_4 , V_10 , V_37 ) ;
if ( V_17 == NULL )
break;
}
}
void T_1 F_27 ( void )
{
struct V_1 * V_39 ;
V_40 = F_25 ( L_7 , NULL ) ;
if ( V_40 == NULL )
return;
V_39 = F_28 ( L_8 ) ;
if ( V_39 == NULL ) {
F_12 ( L_7 , NULL ) ;
F_29 ( L_9 ) ;
return;
}
F_22 ( V_39 , V_40 ) ;
F_26 ( V_39 ) ;
}
