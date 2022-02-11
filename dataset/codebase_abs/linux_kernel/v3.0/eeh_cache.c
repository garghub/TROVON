static inline struct V_1 * F_1 ( unsigned long V_2 )
{
struct V_3 * V_4 = V_5 . V_6 . V_3 ;
while ( V_4 ) {
struct V_7 * V_8 ;
V_8 = F_2 ( V_4 , struct V_7 , V_3 ) ;
if ( V_2 < V_8 -> V_9 ) {
V_4 = V_4 -> V_10 ;
} else {
if ( V_2 > V_8 -> V_11 ) {
V_4 = V_4 -> V_12 ;
} else {
F_3 ( V_8 -> V_13 ) ;
return V_8 -> V_13 ;
}
}
}
return NULL ;
}
struct V_1 * F_4 ( unsigned long V_2 )
{
struct V_1 * V_14 ;
unsigned long V_15 ;
F_5 ( & V_5 . V_16 , V_15 ) ;
V_14 = F_1 ( V_2 ) ;
F_6 ( & V_5 . V_16 , V_15 ) ;
return V_14 ;
}
static void F_7 ( struct V_17 * V_18 )
{
struct V_3 * V_4 ;
int V_19 = 0 ;
V_4 = F_8 ( & V_18 -> V_6 ) ;
while ( V_4 ) {
struct V_7 * V_8 ;
V_8 = F_2 ( V_4 , struct V_7 , V_3 ) ;
F_9 ( V_20 L_1 ,
( V_8 -> V_15 & V_21 ) ? L_2 : L_3 , V_19 ,
V_8 -> V_9 , V_8 -> V_11 , F_10 ( V_8 -> V_13 ) ) ;
V_19 ++ ;
V_4 = F_11 ( V_4 ) ;
}
}
static struct V_7 *
F_12 ( struct V_1 * V_14 , unsigned long V_22 ,
unsigned long V_23 , unsigned int V_15 )
{
struct V_3 * * V_24 = & V_5 . V_6 . V_3 ;
struct V_3 * V_25 = NULL ;
struct V_7 * V_8 ;
while ( * V_24 ) {
V_25 = * V_24 ;
V_8 = F_2 ( V_25 , struct V_7 , V_3 ) ;
if ( V_23 < V_8 -> V_9 ) {
V_24 = & V_25 -> V_10 ;
} else if ( V_22 > V_8 -> V_11 ) {
V_24 = & V_25 -> V_12 ;
} else {
if ( V_14 != V_8 -> V_13 ||
V_22 != V_8 -> V_9 || V_23 != V_8 -> V_11 ) {
F_9 ( V_26 L_4 ) ;
}
return V_8 ;
}
}
V_8 = F_13 ( sizeof( struct V_7 ) , V_27 ) ;
if ( ! V_8 )
return NULL ;
F_3 ( V_14 ) ;
V_8 -> V_9 = V_22 ;
V_8 -> V_11 = V_23 ;
V_8 -> V_13 = V_14 ;
V_8 -> V_15 = V_15 ;
#ifdef F_14
F_9 ( V_20 L_5 ,
V_22 , V_23 , F_10 ( V_14 ) ) ;
#endif
F_15 ( & V_8 -> V_3 , V_25 , V_24 ) ;
F_16 ( & V_8 -> V_3 , & V_5 . V_6 ) ;
return V_8 ;
}
static void F_17 ( struct V_1 * V_14 )
{
struct V_28 * V_29 ;
struct V_30 * V_31 ;
int V_32 ;
V_29 = F_18 ( V_14 ) ;
if ( ! V_29 ) {
F_9 ( V_26 L_6 , F_10 ( V_14 ) ) ;
return;
}
V_31 = F_19 ( V_29 ) ;
if ( ! ( V_31 -> V_33 & V_34 ) ||
V_31 -> V_33 & V_35 ) {
#ifdef F_14
F_9 ( V_36 L_7 ,
F_10 ( V_14 ) , V_31 -> V_37 -> V_38 ) ;
#endif
return;
}
for ( V_32 = 0 ; V_32 < V_39 ; V_32 ++ ) {
unsigned long V_40 = F_20 ( V_14 , V_32 ) ;
unsigned long V_41 = F_21 ( V_14 , V_32 ) ;
unsigned int V_15 = F_22 ( V_14 , V_32 ) ;
if ( 0 == ( V_15 & ( V_21 | V_42 ) ) )
continue;
if ( V_40 == 0 || ~ V_40 == 0 || V_41 == 0 || ~ V_41 == 0 )
continue;
F_12 ( V_14 , V_40 , V_41 , V_15 ) ;
}
}
void F_23 ( struct V_1 * V_14 )
{
unsigned long V_15 ;
if ( ( V_14 -> V_43 >> 16 ) == V_44 )
return;
F_5 ( & V_5 . V_16 , V_15 ) ;
F_17 ( V_14 ) ;
F_6 ( & V_5 . V_16 , V_15 ) ;
}
static inline void F_24 ( struct V_1 * V_14 )
{
struct V_3 * V_4 ;
V_45:
V_4 = F_8 ( & V_5 . V_6 ) ;
while ( V_4 ) {
struct V_7 * V_8 ;
V_8 = F_2 ( V_4 , struct V_7 , V_3 ) ;
if ( V_8 -> V_13 == V_14 ) {
F_25 ( V_4 , & V_5 . V_6 ) ;
F_26 ( V_8 -> V_13 ) ;
F_27 ( V_8 ) ;
goto V_45;
}
V_4 = F_11 ( V_4 ) ;
}
}
void F_28 ( struct V_1 * V_14 )
{
unsigned long V_15 ;
F_5 ( & V_5 . V_16 , V_15 ) ;
F_24 ( V_14 ) ;
F_6 ( & V_5 . V_16 , V_15 ) ;
}
void T_1 F_29 ( void )
{
struct V_28 * V_29 ;
struct V_1 * V_14 = NULL ;
F_30 ( & V_5 . V_16 ) ;
F_31 (dev) {
F_23 ( V_14 ) ;
V_29 = F_18 ( V_14 ) ;
if ( ! V_29 )
continue;
F_3 ( V_14 ) ;
F_19 ( V_29 ) -> V_13 = V_14 ;
F_32 ( V_14 ) ;
}
#ifdef F_14
F_7 ( & V_5 ) ;
#endif
}
