struct V_1 * F_1 ( struct V_2 * V_3 , T_1 V_4 )
{
struct V_1 * V_5 ;
if ( V_4 > V_6 )
return NULL ;
V_5 = F_2 ( sizeof( struct V_1 ) , V_7 ) ;
if ( V_5 == NULL )
return NULL ;
V_5 -> V_8 = F_2 ( V_4 , V_7 ) ;
if ( V_5 -> V_8 == NULL ) {
F_3 ( V_5 ) ;
return NULL ;
}
V_5 -> V_4 = V_4 ;
F_4 ( & V_5 -> V_9 ) ;
V_5 -> V_10 = & V_3 -> V_10 ;
V_5 -> V_11 = V_12 ;
F_5 ( & V_5 -> V_13 ) ;
F_6 ( & V_5 -> V_14 ) ;
F_7 ( & V_15 ) ;
F_8 ( L_1 , F_9 ( & V_15 ) ) ;
return V_5 ;
}
void F_10 ( struct V_9 * V_9 )
{
struct V_1 * V_5 = F_11 ( V_9 ) ;
F_12 ( & V_5 -> V_14 ) ;
F_13 ( & V_15 ) ;
F_8 ( L_1 , F_9 ( & V_15 ) ) ;
F_3 ( V_5 -> V_8 ) ;
F_3 ( V_5 ) ;
}
static void F_14 ( struct V_2 * V_3 , struct V_1 * V_5 )
{
F_15 ( & V_5 -> V_14 , & V_3 -> V_16 ) ;
}
static struct V_1 * F_16 ( struct V_2 * V_3 )
{
struct V_1 * V_5 ;
struct V_17 * V_18 ;
if ( F_17 ( & V_3 -> V_16 ) )
return NULL ;
V_18 = V_3 -> V_16 . V_18 ;
F_18 ( V_18 ) ;
V_5 = F_19 ( V_18 , struct V_1 , V_14 ) ;
return V_5 ;
}
static inline void F_20 ( struct V_2 * V_3 )
{
char V_19 [ 32 ] ;
F_8 ( L_2 , V_20 , __LINE__ , F_21 ( V_19 ) ) ;
if ( F_22 ( V_3 ) ) {
V_3 -> V_21 -> V_11 = V_22 ;
F_23 ( & V_3 -> V_21 -> V_13 ) ;
F_24 ( V_3 -> V_21 ) ;
F_25 ( V_3 ) ;
}
}
void F_26 ( struct V_2 * V_3 , struct V_1 * V_5 )
{
unsigned long V_23 ;
char V_19 [ 32 ] ;
F_8 ( L_2 , V_20 , __LINE__ , F_21 ( V_19 ) ) ;
F_27 ( & V_3 -> V_10 , V_23 ) ;
if ( ! V_3 -> V_21 ) {
V_3 -> V_21 = V_5 ;
F_28 ( V_3 -> V_21 ) ;
F_29 ( & V_3 -> V_10 , V_23 ) ;
F_20 ( V_3 ) ;
} else {
F_14 ( V_3 , V_5 ) ;
F_29 ( & V_3 -> V_10 , V_23 ) ;
}
}
static void F_25 ( struct V_2 * V_3 )
{
unsigned long V_23 ;
char V_19 [ 32 ] ;
F_8 ( L_2 , V_20 , __LINE__ , F_21 ( V_19 ) ) ;
F_27 ( & V_3 -> V_10 , V_23 ) ;
V_3 -> V_21 = F_16 ( V_3 ) ;
if ( V_3 -> V_21 ) {
F_28 ( V_3 -> V_21 ) ;
F_29 ( & V_3 -> V_10 , V_23 ) ;
F_20 ( V_3 ) ;
} else {
F_29 ( & V_3 -> V_10 , V_23 ) ;
}
}
void F_30 ( struct V_1 * V_5 , int V_24 )
{
F_31 ( V_5 -> V_13 ,
V_5 -> V_11 == V_25 ||
V_5 -> V_11 == V_22 ,
V_24 * V_26 ) ;
}
void F_32 ( struct V_2 * V_3 , void * V_27 , T_1 V_28 )
{
struct V_1 * V_5 = V_3 -> V_21 ;
if ( ! V_3 -> V_21 )
return;
F_33 ( V_5 -> V_8 , V_27 , F_34 ( V_28 , V_5 -> V_4 ) ) ;
V_5 -> V_11 = V_25 ;
F_23 ( & V_3 -> V_21 -> V_13 ) ;
F_24 ( V_3 -> V_21 ) ;
F_25 ( V_3 ) ;
}
