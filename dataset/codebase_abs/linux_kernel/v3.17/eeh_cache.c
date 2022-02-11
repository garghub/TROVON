static inline struct V_1 * F_1 ( unsigned long V_2 )
{
struct V_3 * V_4 = V_5 . V_6 . V_3 ;
while ( V_4 ) {
struct V_7 * V_8 ;
V_8 = F_2 ( V_4 , struct V_7 , V_3 ) ;
if ( V_2 < V_8 -> V_9 )
V_4 = V_4 -> V_10 ;
else if ( V_2 > V_8 -> V_11 )
V_4 = V_4 -> V_12 ;
else
return V_8 -> V_13 ;
}
return NULL ;
}
struct V_1 * F_3 ( unsigned long V_2 )
{
struct V_1 * V_13 ;
unsigned long V_14 ;
F_4 ( & V_5 . V_15 , V_14 ) ;
V_13 = F_1 ( V_2 ) ;
F_5 ( & V_5 . V_15 , V_14 ) ;
return V_13 ;
}
static void F_6 ( struct V_16 * V_17 )
{
struct V_3 * V_4 ;
int V_18 = 0 ;
V_4 = F_7 ( & V_17 -> V_6 ) ;
while ( V_4 ) {
struct V_7 * V_8 ;
V_8 = F_2 ( V_4 , struct V_7 , V_3 ) ;
F_8 ( L_1 ,
( V_8 -> V_14 & V_19 ) ? L_2 : L_3 , V_18 ,
V_8 -> V_9 , V_8 -> V_11 , F_9 ( V_8 -> V_20 ) ) ;
V_18 ++ ;
V_4 = F_10 ( V_4 ) ;
}
}
static struct V_7 *
F_11 ( struct V_21 * V_22 , unsigned long V_23 ,
unsigned long V_24 , unsigned int V_14 )
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
if ( V_22 != V_8 -> V_20 ||
V_23 != V_8 -> V_9 || V_24 != V_8 -> V_11 ) {
F_12 ( L_4 ) ;
}
return V_8 ;
}
}
V_8 = F_13 ( sizeof( struct V_7 ) , V_27 ) ;
if ( ! V_8 )
return NULL ;
V_8 -> V_9 = V_23 ;
V_8 -> V_11 = V_24 ;
V_8 -> V_13 = F_14 ( V_22 ) ;
V_8 -> V_20 = V_22 ;
V_8 -> V_14 = V_14 ;
#ifdef F_15
F_8 ( L_5 ,
V_23 , V_24 , F_9 ( V_22 ) ) ;
#endif
F_16 ( & V_8 -> V_3 , V_26 , V_25 ) ;
F_17 ( & V_8 -> V_3 , & V_5 . V_6 ) ;
return V_8 ;
}
static void F_18 ( struct V_21 * V_22 )
{
struct V_28 * V_29 ;
struct V_1 * V_13 ;
int V_30 ;
V_29 = F_19 ( V_22 ) ;
if ( ! V_29 ) {
F_12 ( L_6 ,
F_9 ( V_22 ) ) ;
return;
}
V_13 = F_20 ( V_29 ) ;
if ( ! V_13 ) {
F_12 ( L_7 ,
V_29 -> V_31 ) ;
return;
}
if ( ! V_13 -> V_32 ) {
#ifdef F_15
F_21 ( L_8 ,
F_9 ( V_22 ) , V_29 -> V_31 ) ;
#endif
return;
}
for ( V_30 = 0 ; V_30 < V_33 ; V_30 ++ ) {
unsigned long V_34 = F_22 ( V_22 , V_30 ) ;
unsigned long V_35 = F_23 ( V_22 , V_30 ) ;
unsigned int V_14 = F_24 ( V_22 , V_30 ) ;
if ( 0 == ( V_14 & ( V_19 | V_36 ) ) )
continue;
if ( V_34 == 0 || ~ V_34 == 0 || V_35 == 0 || ~ V_35 == 0 )
continue;
F_11 ( V_22 , V_34 , V_35 , V_14 ) ;
}
}
void F_25 ( struct V_21 * V_22 )
{
unsigned long V_14 ;
if ( ( V_22 -> V_37 >> 16 ) == V_38 )
return;
F_4 ( & V_5 . V_15 , V_14 ) ;
F_18 ( V_22 ) ;
F_5 ( & V_5 . V_15 , V_14 ) ;
}
static inline void F_26 ( struct V_21 * V_22 )
{
struct V_3 * V_4 ;
V_39:
V_4 = F_7 ( & V_5 . V_6 ) ;
while ( V_4 ) {
struct V_7 * V_8 ;
V_8 = F_2 ( V_4 , struct V_7 , V_3 ) ;
if ( V_8 -> V_20 == V_22 ) {
F_27 ( V_4 , & V_5 . V_6 ) ;
F_28 ( V_8 ) ;
goto V_39;
}
V_4 = F_10 ( V_4 ) ;
}
}
void F_29 ( struct V_21 * V_22 )
{
unsigned long V_14 ;
F_4 ( & V_5 . V_15 , V_14 ) ;
F_26 ( V_22 ) ;
F_5 ( & V_5 . V_15 , V_14 ) ;
}
void F_30 ( void )
{
struct V_28 * V_29 ;
struct V_1 * V_13 ;
struct V_21 * V_22 = NULL ;
F_31 ( & V_5 . V_15 ) ;
F_32 (dev) {
V_29 = F_19 ( V_22 ) ;
if ( ! V_29 )
continue;
V_13 = F_20 ( V_29 ) ;
if ( ! V_13 )
continue;
V_22 -> V_22 . V_40 . V_13 = V_13 ;
V_13 -> V_41 = V_22 ;
F_25 ( V_22 ) ;
F_33 ( V_22 ) ;
}
#ifdef F_15
F_6 ( & V_5 ) ;
#endif
}
