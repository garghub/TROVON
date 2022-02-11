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
return V_8 -> V_14 ;
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
F_9 ( L_1 ,
( V_8 -> V_15 & V_20 ) ? L_2 : L_3 , V_19 ,
V_8 -> V_9 , V_8 -> V_11 , F_10 ( V_8 -> V_13 ) ) ;
V_19 ++ ;
V_4 = F_11 ( V_4 ) ;
}
}
static struct V_7 *
F_12 ( struct V_21 * V_22 , unsigned long V_23 ,
unsigned long V_24 , unsigned int V_15 )
{
struct V_3 * * V_25 = & V_5 . V_6 . V_3 ;
struct V_3 * V_26 = NULL ;
struct V_7 * V_8 ;
while ( * V_25 ) {
V_26 = * V_25 ;
V_8 = F_2 ( V_26 , struct V_7 , V_3 ) ;
if ( V_24 < V_8 -> V_9 ) {
V_25 = & V_26 -> V_10 ;
} else if ( V_23 > V_8 -> V_11 ) {
V_25 = & V_26 -> V_12 ;
} else {
if ( V_22 != V_8 -> V_13 ||
V_23 != V_8 -> V_9 || V_24 != V_8 -> V_11 ) {
F_13 ( L_4 ) ;
}
return V_8 ;
}
}
V_8 = F_14 ( sizeof( struct V_7 ) , V_27 ) ;
if ( ! V_8 )
return NULL ;
F_3 ( V_22 ) ;
V_8 -> V_9 = V_23 ;
V_8 -> V_11 = V_24 ;
V_8 -> V_14 = F_15 ( V_22 ) ;
V_8 -> V_13 = V_22 ;
V_8 -> V_15 = V_15 ;
#ifdef F_16
F_9 ( L_5 ,
V_23 , V_24 , F_10 ( V_22 ) ) ;
#endif
F_17 ( & V_8 -> V_3 , V_26 , V_25 ) ;
F_18 ( & V_8 -> V_3 , & V_5 . V_6 ) ;
return V_8 ;
}
static void F_19 ( struct V_21 * V_22 )
{
struct V_28 * V_29 ;
struct V_1 * V_14 ;
int V_30 ;
V_29 = F_20 ( V_22 ) ;
if ( ! V_29 ) {
F_13 ( L_6 , F_10 ( V_22 ) ) ;
return;
}
V_14 = F_21 ( V_29 ) ;
if ( ! V_14 ) {
F_13 ( L_7 ,
V_29 -> V_31 ) ;
return;
}
if ( ! V_14 -> V_32 ) {
#ifdef F_16
F_22 ( L_8 ,
F_10 ( V_22 ) , V_29 -> V_31 ) ;
#endif
return;
}
for ( V_30 = 0 ; V_30 < V_33 ; V_30 ++ ) {
unsigned long V_34 = F_23 ( V_22 , V_30 ) ;
unsigned long V_35 = F_24 ( V_22 , V_30 ) ;
unsigned int V_15 = F_25 ( V_22 , V_30 ) ;
if ( 0 == ( V_15 & ( V_20 | V_36 ) ) )
continue;
if ( V_34 == 0 || ~ V_34 == 0 || V_35 == 0 || ~ V_35 == 0 )
continue;
F_12 ( V_22 , V_34 , V_35 , V_15 ) ;
}
}
void F_26 ( struct V_21 * V_22 )
{
unsigned long V_15 ;
if ( ( V_22 -> V_37 >> 16 ) == V_38 )
return;
F_5 ( & V_5 . V_16 , V_15 ) ;
F_19 ( V_22 ) ;
F_6 ( & V_5 . V_16 , V_15 ) ;
}
static inline void F_27 ( struct V_21 * V_22 )
{
struct V_3 * V_4 ;
V_39:
V_4 = F_8 ( & V_5 . V_6 ) ;
while ( V_4 ) {
struct V_7 * V_8 ;
V_8 = F_2 ( V_4 , struct V_7 , V_3 ) ;
if ( V_8 -> V_13 == V_22 ) {
F_28 ( V_4 , & V_5 . V_6 ) ;
F_29 ( V_8 -> V_13 ) ;
F_30 ( V_8 ) ;
goto V_39;
}
V_4 = F_11 ( V_4 ) ;
}
}
void F_31 ( struct V_21 * V_22 )
{
unsigned long V_15 ;
F_5 ( & V_5 . V_16 , V_15 ) ;
F_27 ( V_22 ) ;
F_6 ( & V_5 . V_16 , V_15 ) ;
}
void T_1 F_32 ( void )
{
struct V_28 * V_29 ;
struct V_1 * V_14 ;
struct V_21 * V_22 = NULL ;
F_33 ( & V_5 . V_16 ) ;
F_34 (dev) {
V_29 = F_20 ( V_22 ) ;
if ( ! V_29 )
continue;
V_14 = F_21 ( V_29 ) ;
if ( ! V_14 )
continue;
F_3 ( V_22 ) ;
V_22 -> V_22 . V_40 . V_14 = V_14 ;
V_14 -> V_41 = V_22 ;
F_26 ( V_22 ) ;
F_35 ( V_22 ) ;
}
#ifdef F_16
F_7 ( & V_5 ) ;
#endif
}
