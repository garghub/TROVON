void F_1 ( struct V_1 * V_2 )
{
if ( F_2 ( V_3 , V_2 -> V_4 ) ) {
F_3 ( V_2 -> V_5 , V_2 -> V_6 ) ;
F_4 ( V_2 ) ;
}
}
static void F_5 ( struct V_1 * V_2 )
{
if ( ! F_2 ( V_3 , V_2 -> V_4 ) )
return;
F_6 ( V_2 -> V_5 , V_2 -> V_6 , V_2 -> V_7 ) ;
}
void F_4 ( struct V_1 * V_2 )
{
if ( ! F_2 ( V_3 , V_2 -> V_4 ) )
return;
F_6 ( V_2 -> V_5 , V_2 -> V_6 , ! V_2 -> V_7 ) ;
}
static void
F_7 ( struct V_8 * V_9 ,
enum V_10 V_11 )
{
struct V_12 * V_13 = F_8 ( V_9 , struct V_12 ,
V_9 ) ;
if ( V_11 == V_14 )
F_4 ( V_13 -> V_2 ) ;
else
F_5 ( V_13 -> V_2 ) ;
}
static int
F_9 ( struct V_1 * V_2 , struct V_12 * V_13 ,
const char * V_15 , char * V_16 )
{
int V_17 ;
V_13 -> V_2 = V_2 ;
strncpy ( V_13 -> V_15 , V_15 , sizeof( V_13 -> V_15 ) ) ;
V_13 -> V_9 . V_15 = V_13 -> V_15 ;
V_13 -> V_9 . V_18 = V_16 ;
V_13 -> V_9 . V_19 = F_7 ;
V_17 = F_10 ( V_2 -> V_20 , & V_13 -> V_9 ) ;
if ( V_17 ) {
F_11 ( V_2 , L_1 , V_15 ) ;
V_13 -> V_2 = NULL ;
}
return V_17 ;
}
static void
F_12 ( struct V_12 * V_13 )
{
if ( ! V_13 -> V_2 )
return;
F_13 ( & V_13 -> V_9 ) ;
F_4 ( V_13 -> V_2 ) ;
V_13 -> V_2 = NULL ;
}
void F_14 ( struct V_1 * V_2 )
{
F_12 ( & V_2 -> V_21 ) ;
F_12 ( & V_2 -> V_22 ) ;
}
int F_15 ( struct V_1 * V_2 )
{
int V_23 = 0 ;
struct V_24 * V_25 = V_2 -> V_25 ;
#ifndef F_16
struct V_26 * V_27 = V_2 -> V_27 ;
#endif
char V_15 [ V_28 + 1 ] ;
const struct V_29 * V_30 ;
if ( ! V_2 -> V_27 )
return 0 ;
#ifdef F_16
V_30 = NULL ;
#else
V_30 = F_17 ( & V_31 [ 0 ] , V_27 ) ;
#endif
if ( V_30 ) {
F_18 ( V_3 , V_2 -> V_4 ) ;
V_2 -> V_6 = F_19 ( V_30 -> V_32 ) ;
V_2 -> V_7 = F_20 ( V_30 -> V_32 ) ;
}
if ( ! F_2 ( V_3 , V_2 -> V_4 ) )
goto V_33;
F_1 ( V_2 ) ;
snprintf ( V_15 , sizeof( V_15 ) , L_2 , F_21 ( V_25 -> V_34 ) ) ;
V_23 = F_9 ( V_2 , & V_2 -> V_21 , V_15 ,
F_22 ( V_25 ) ) ;
if ( V_23 )
goto V_33;
snprintf ( V_15 , sizeof( V_15 ) , L_3 , F_21 ( V_25 -> V_34 ) ) ;
V_23 = F_9 ( V_2 , & V_2 -> V_22 , V_15 ,
F_23 ( V_25 ) ) ;
V_33:
return V_23 ;
}
