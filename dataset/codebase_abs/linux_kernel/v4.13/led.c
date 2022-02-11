void F_1 ( struct V_1 * V_2 )
{
if ( F_2 ( V_3 , V_2 -> V_4 ) ) {
F_3 ( V_2 , V_2 -> V_5 ) ;
F_4 ( V_2 ) ;
}
}
static void F_5 ( struct V_1 * V_2 )
{
if ( ! F_2 ( V_3 , V_2 -> V_4 ) )
return;
F_6 ( V_2 , V_2 -> V_5 , V_2 -> V_6 ) ;
}
void F_4 ( struct V_1 * V_2 )
{
if ( ! F_2 ( V_3 , V_2 -> V_4 ) )
return;
F_6 ( V_2 , V_2 -> V_5 , ! V_2 -> V_6 ) ;
}
static void
F_7 ( struct V_7 * V_8 ,
enum V_9 V_10 )
{
struct V_11 * V_12 = F_8 ( V_8 , struct V_11 ,
V_8 ) ;
if ( V_10 == V_13 )
F_4 ( V_12 -> V_2 ) ;
else
F_5 ( V_12 -> V_2 ) ;
}
static int
F_9 ( struct V_1 * V_2 , struct V_11 * V_12 ,
const char * V_14 , const char * V_15 )
{
int V_16 ;
V_12 -> V_2 = V_2 ;
strncpy ( V_12 -> V_14 , V_14 , sizeof( V_12 -> V_14 ) ) ;
V_12 -> V_14 [ sizeof( V_12 -> V_14 ) - 1 ] = 0 ;
V_12 -> V_8 . V_14 = V_12 -> V_14 ;
V_12 -> V_8 . V_17 = V_15 ;
V_12 -> V_8 . V_18 = F_7 ;
V_16 = F_10 ( V_2 -> V_19 , & V_12 -> V_8 ) ;
if ( V_16 ) {
F_11 ( V_2 , L_1 , V_14 ) ;
V_12 -> V_2 = NULL ;
}
return V_16 ;
}
static void
F_12 ( struct V_11 * V_12 )
{
if ( ! V_12 -> V_2 )
return;
F_13 ( & V_12 -> V_8 ) ;
F_4 ( V_12 -> V_2 ) ;
V_12 -> V_2 = NULL ;
}
void F_14 ( struct V_1 * V_2 )
{
F_12 ( & V_2 -> V_20 ) ;
F_12 ( & V_2 -> V_21 ) ;
}
int F_15 ( struct V_1 * V_2 )
{
int V_22 = 0 ;
struct V_23 * V_24 = V_2 -> V_24 ;
#ifndef F_16
struct V_25 * V_26 = V_2 -> V_26 ;
#endif
char V_14 [ V_27 + 1 ] ;
const struct V_28 * V_29 ;
if ( ! V_2 -> V_26 )
return 0 ;
#ifdef F_16
V_29 = NULL ;
#else
V_29 = F_17 ( & V_30 [ 0 ] , V_26 ) ;
#endif
if ( V_29 ) {
F_18 ( V_3 , V_2 -> V_4 ) ;
V_2 -> V_5 = F_19 ( V_29 -> V_31 ) ;
V_2 -> V_6 = F_20 ( V_29 -> V_31 ) ;
}
if ( ! F_2 ( V_3 , V_2 -> V_4 ) )
goto V_32;
F_1 ( V_2 ) ;
snprintf ( V_14 , sizeof( V_14 ) , L_2 , F_21 ( V_24 -> V_33 ) ) ;
V_22 = F_9 ( V_2 , & V_2 -> V_20 , V_14 ,
F_22 ( V_24 ) ) ;
if ( V_22 )
goto V_32;
snprintf ( V_14 , sizeof( V_14 ) , L_3 , F_21 ( V_24 -> V_33 ) ) ;
V_22 = F_9 ( V_2 , & V_2 -> V_21 , V_14 ,
F_23 ( V_24 ) ) ;
V_32:
return V_22 ;
}
