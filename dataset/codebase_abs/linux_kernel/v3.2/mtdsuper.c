static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_3 ;
if ( V_2 -> V_6 == V_5 ) {
F_2 ( L_1 ,
V_5 -> V_7 , V_5 -> V_8 ) ;
return 1 ;
}
F_2 ( L_2 ,
V_2 -> V_6 -> V_7 , V_2 -> V_6 -> V_8 , V_5 -> V_7 , V_5 -> V_8 ) ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_3 ;
V_2 -> V_6 = V_5 ;
V_2 -> V_9 = F_4 ( V_10 , V_5 -> V_7 ) ;
V_2 -> V_11 = V_5 -> V_12 ;
return 0 ;
}
static struct V_13 * F_5 ( struct V_14 * V_15 , int V_16 ,
const char * V_17 , void * V_18 ,
struct V_4 * V_5 ,
int (* F_6)( struct V_1 * , void * , int ) )
{
struct V_1 * V_2 ;
int V_19 ;
V_2 = F_7 ( V_15 , F_1 , F_3 , V_5 ) ;
if ( F_8 ( V_2 ) )
goto V_20;
if ( V_2 -> V_21 )
goto V_22;
F_2 ( L_3 ,
V_5 -> V_7 , V_5 -> V_8 ) ;
V_2 -> V_23 = V_16 ;
V_19 = F_6 ( V_2 , V_18 , V_16 & V_24 ? 1 : 0 ) ;
if ( V_19 < 0 ) {
F_9 ( V_2 ) ;
return F_10 ( V_19 ) ;
}
V_2 -> V_23 |= V_25 ;
return F_11 ( V_2 -> V_21 ) ;
V_22:
F_2 ( L_4 ,
V_5 -> V_7 , V_5 -> V_8 ) ;
F_12 ( V_5 ) ;
return F_11 ( V_2 -> V_21 ) ;
V_20:
F_12 ( V_5 ) ;
return F_13 ( V_2 ) ;
}
static struct V_13 * F_14 ( struct V_14 * V_15 , int V_16 ,
const char * V_17 , void * V_18 , int V_26 ,
int (* F_6)( struct V_1 * , void * , int ) )
{
struct V_4 * V_5 ;
V_5 = F_15 ( NULL , V_26 ) ;
if ( F_8 ( V_5 ) ) {
F_2 ( L_5 , V_26 ) ;
return F_13 ( V_5 ) ;
}
return F_5 ( V_15 , V_16 , V_17 , V_18 , V_5 , F_6 ) ;
}
struct V_13 * F_16 ( struct V_14 * V_15 , int V_16 ,
const char * V_17 , void * V_18 ,
int (* F_6)( struct V_1 * , void * , int ) )
{
#ifdef F_17
struct V_27 * V_28 ;
int V_19 , V_29 ;
#endif
int V_26 ;
if ( ! V_17 )
return F_10 ( - V_30 ) ;
F_2 ( L_6 , V_17 ) ;
if ( V_17 [ 0 ] == 'm' && V_17 [ 1 ] == 't' && V_17 [ 2 ] == 'd' ) {
if ( V_17 [ 3 ] == ':' ) {
struct V_4 * V_5 ;
F_2 ( L_7 ,
V_17 + 4 ) ;
V_5 = F_18 ( V_17 + 4 ) ;
if ( ! F_8 ( V_5 ) )
return F_5 (
V_15 , V_16 ,
V_17 , V_18 , V_5 ,
F_6 ) ;
F_19 ( V_31 L_8
L_9 ,
V_17 + 4 ) ;
} else if ( isdigit ( V_17 [ 3 ] ) ) {
char * V_32 ;
V_26 = F_20 ( V_17 + 3 , & V_32 , 0 ) ;
if ( ! * V_32 ) {
F_2 ( L_10 ,
V_26 ) ;
return F_14 ( V_15 , V_16 ,
V_17 , V_18 ,
V_26 , F_6 ) ;
}
}
}
#ifdef F_17
V_28 = F_21 ( V_17 ) ;
if ( F_8 ( V_28 ) ) {
V_19 = F_22 ( V_28 ) ;
F_2 ( L_11 , V_19 ) ;
return F_10 ( V_19 ) ;
}
F_2 ( L_12 ) ;
V_19 = - V_30 ;
V_29 = F_23 ( V_28 -> V_33 ) ;
V_26 = F_24 ( V_28 -> V_33 ) ;
F_25 ( V_28 ) ;
if ( V_29 != V_10 )
goto V_34;
return F_14 ( V_15 , V_16 , V_17 , V_18 , V_26 , F_6 ) ;
V_34:
#endif
if ( ! ( V_16 & V_24 ) )
F_19 ( V_31
L_13 ,
V_17 ) ;
return F_10 ( - V_30 ) ;
}
void F_26 ( struct V_1 * V_2 )
{
F_27 ( V_2 ) ;
F_12 ( V_2 -> V_6 ) ;
V_2 -> V_6 = NULL ;
}
