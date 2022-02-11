static int F_1 ( struct V_1 * V_2 )
{
struct V_1 * V_3 ;
int V_4 ;
V_4 = 0 ;
for ( V_3 = V_2 ; V_3 -> V_5 ; V_3 = V_3 -> V_5 )
V_4 ++ ;
return V_4 ;
}
static struct V_1 * F_2 ( struct V_1 * V_2 , int V_6 )
{
int V_7 ;
for ( V_7 = 0 ; V_2 && V_7 < V_6 ; V_7 ++ )
V_2 = V_2 -> V_5 ;
return V_2 ;
}
static void F_3 ( struct V_1 * V_2 )
{
struct V_1 * V_3 ;
int V_4 , V_7 ;
V_4 = F_1 ( V_2 ) ;
if ( V_2 -> V_8 ) {
for ( V_7 = V_4 ; V_7 >= 0 ; V_7 -- ) {
V_3 = F_2 ( V_2 , V_7 ) ;
F_4 ( L_1 , V_3 -> V_8 ? V_3 -> V_8 : L_2 ) ;
}
}
F_4 ( L_3 ) ;
}
static struct V_1 * F_5 ( struct V_9 * V_10 ,
struct V_1 * V_2 )
{
struct V_11 * V_12 ;
struct V_1 * V_13 , * V_14 ;
int V_4 , V_15 ;
V_4 = F_1 ( V_2 ) ;
for ( V_12 = F_6 ( V_10 , NULL ) ; V_12 ;
V_12 = F_6 ( V_10 , V_12 ) ) {
V_15 = V_4 ;
V_13 = V_12 -> V_1 ;
V_16:
V_14 = F_2 ( V_2 , V_15 ) ;
for (; V_13 -> V_8 ; V_13 ++ ) {
int V_17 = 0 ;
if ( V_15 && ! V_13 -> V_18 )
continue;
if ( V_14 -> V_8 && V_13 -> V_8 &&
( strcmp ( V_14 -> V_8 , V_13 -> V_8 ) == 0 ) )
V_17 ++ ;
if ( V_17 ) {
if ( V_15 != 0 ) {
V_15 -- ;
V_13 = V_13 -> V_18 ;
goto V_16;
}
goto V_19;
}
}
}
V_13 = NULL ;
V_19:
F_7 ( V_12 ) ;
return V_13 ;
}
static void F_8 ( const char * * V_20 , struct V_1 * V_2 , const char * V_21 )
{
if ( * V_20 ) {
F_4 ( V_22 L_4 ) ;
F_3 ( V_2 ) ;
F_4 ( L_5 , * V_20 ) ;
F_9 () ;
}
* V_20 = V_21 ;
}
static void F_10 ( struct V_9 * V_10 ,
struct V_1 * V_2 , const char * * V_20 )
{
struct V_1 * V_13 ;
V_13 = F_5 ( V_10 , V_2 ) ;
if ( V_13 && ( V_13 != V_2 ) )
F_8 ( V_20 , V_2 , L_6 ) ;
}
int F_11 ( struct V_9 * V_10 , struct V_1 * V_2 )
{
int error = 0 ;
for (; V_2 -> V_8 ; V_2 ++ ) {
const char * V_20 = NULL ;
if ( V_2 -> V_5 ) {
if ( ! V_2 -> V_5 -> V_8 )
F_8 ( & V_20 , V_2 , L_7 ) ;
}
if ( V_2 -> V_18 ) {
if ( V_2 -> V_23 )
F_8 ( & V_20 , V_2 , L_8 ) ;
if ( V_2 -> V_24 )
F_8 ( & V_20 , V_2 , L_9 ) ;
if ( ( V_2 -> V_25 & ( V_26 | V_27 ) ) != V_2 -> V_25 )
F_8 ( & V_20 , V_2 , L_10 ) ;
if ( V_2 -> V_28 )
F_8 ( & V_20 , V_2 , L_11 ) ;
if ( V_2 -> V_29 )
F_8 ( & V_20 , V_2 , L_12 ) ;
if ( V_2 -> V_30 )
F_8 ( & V_20 , V_2 , L_13 ) ;
} else {
if ( ( V_2 -> V_28 == V_31 ) ||
( V_2 -> V_28 == V_32 ) ||
( V_2 -> V_28 == V_33 ) ||
( V_2 -> V_28 == V_34 ) ||
( V_2 -> V_28 == V_35 ) ||
( V_2 -> V_28 == V_36 ) ||
( V_2 -> V_28 == V_37 ) ||
( V_2 -> V_28 == V_38 ) ) {
if ( ! V_2 -> V_23 )
F_8 ( & V_20 , V_2 , L_14 ) ;
if ( ! V_2 -> V_24 )
F_8 ( & V_20 , V_2 , L_15 ) ;
}
#ifdef F_12
if ( ! V_2 -> V_28 )
F_8 ( & V_20 , V_2 , L_16 ) ;
#endif
F_10 ( V_10 , V_2 , & V_20 ) ;
}
if ( V_2 -> V_25 > 0777 )
F_8 ( & V_20 , V_2 , L_17 ) ;
if ( V_20 ) {
F_8 ( & V_20 , V_2 , NULL ) ;
error = - V_39 ;
}
if ( V_2 -> V_18 )
error |= F_11 ( V_10 , V_2 -> V_18 ) ;
}
return error ;
}
