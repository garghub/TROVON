static void F_1 ( struct V_1 * V_2 , struct V_1 * V_3 ,
struct V_1 * V_4 )
{
F_2 ( V_4 -> V_5 != V_3 || V_3 -> V_6 != V_4 ,
L_1
L_2
L_3 ,
V_2 , V_2 -> V_6 , V_2 -> V_5 ,
V_3 , V_3 -> V_6 , V_3 -> V_5 ,
V_4 , V_4 -> V_6 , V_4 -> V_5 ) ;
}
static void F_3 ( struct V_1 * V_7 )
{
struct V_1 * V_5 = V_7 , * V_6 = V_7 -> V_6 ;
F_1 ( V_7 , V_5 , V_6 ) ;
while ( V_6 != V_7 ) {
V_5 = V_6 ;
V_6 = V_5 -> V_6 ;
F_1 ( V_7 , V_5 , V_6 ) ;
}
}
static void F_4 ( struct V_8 * V_9 )
{
F_5 ( V_9 != & V_10 && ! V_9 -> V_11 && ! V_9 -> V_12 ) ;
if ( V_9 -> V_11 )
F_6 ( ! F_7 ( V_9 -> V_11 ) ) ;
if ( V_9 -> V_12 )
F_6 ( ! F_8 ( V_9 -> V_12 ) ) ;
if ( ! F_9 ( V_9 ) )
F_3 ( & F_10 ( V_9 ) -> V_13 ) ;
F_3 ( & V_9 -> V_14 ) ;
}
void F_11 ( struct V_15 * V_16 , struct V_8 * V_9 )
{
struct V_15 * V_17 , * V_18 , * V_5 = NULL ;
struct V_1 * V_19 = & V_9 -> V_14 ;
F_4 ( V_9 ) ;
F_5 ( ! F_12 ( V_16 ) ) ;
F_5 ( ! F_13 ( & V_16 -> V_13 ) ) ;
if ( F_9 ( V_9 ) )
goto V_20;
V_17 = V_18 = F_10 ( V_9 ) ;
do {
if ( V_16 -> V_21 < V_18 -> V_21 ) {
V_19 = & V_18 -> V_14 ;
break;
}
V_5 = V_18 ;
V_18 = F_14 ( V_18 -> V_13 . V_6 ,
struct V_15 , V_13 ) ;
} while ( V_18 != V_17 );
if ( ! V_5 || V_5 -> V_21 != V_16 -> V_21 )
F_15 ( & V_16 -> V_13 , & V_18 -> V_13 ) ;
V_20:
F_15 ( & V_16 -> V_14 , V_19 ) ;
F_4 ( V_9 ) ;
}
void F_16 ( struct V_15 * V_16 , struct V_8 * V_9 )
{
F_4 ( V_9 ) ;
if ( ! F_13 ( & V_16 -> V_13 ) ) {
if ( V_16 -> V_14 . V_6 != & V_9 -> V_14 ) {
struct V_15 * V_6 ;
V_6 = F_14 ( V_16 -> V_14 . V_6 ,
struct V_15 , V_14 ) ;
if ( F_13 ( & V_6 -> V_13 ) )
F_17 ( & V_6 -> V_13 , & V_16 -> V_13 ) ;
}
F_18 ( & V_16 -> V_13 ) ;
}
F_18 ( & V_16 -> V_14 ) ;
F_4 ( V_9 ) ;
}
static void T_1 F_19 ( int V_22 )
{
struct V_15 * V_17 , * V_23 , * V_24 ;
if ( F_9 ( & V_10 ) ) {
F_20 ( V_22 != 0 ) ;
return;
}
V_23 = V_17 = F_10 ( & V_10 ) ;
F_21 (node_pos, &test_head) {
if ( V_22 -- < 0 )
break;
if ( V_24 == V_17 )
continue;
if ( V_24 -> V_21 == V_23 -> V_21 ) {
F_20 ( ! F_13 ( & V_24 -> V_13 ) ) ;
continue;
}
F_20 ( V_23 -> V_21 > V_24 -> V_21 ) ;
F_20 ( V_23 -> V_13 . V_6 != & V_24 -> V_13 ) ;
V_23 = V_24 ;
}
F_20 ( V_22 != 0 ) ;
F_20 ( V_23 -> V_13 . V_6 != & V_17 -> V_13 ) ;
}
static int T_1 F_22 ( void )
{
int V_22 = 0 , V_25 , V_26 ;
unsigned int V_27 = F_23 () ;
F_24 ( V_28 L_4 ) ;
F_25 ( & V_10 , NULL ) ;
for ( V_25 = 0 ; V_25 < F_26 ( V_29 ) ; V_25 ++ )
F_27 ( V_29 + V_25 , 0 ) ;
for ( V_26 = 0 ; V_26 < 1000 ; V_26 ++ ) {
V_27 = V_27 * 193939 % 47629 ;
V_25 = V_27 % F_26 ( V_29 ) ;
if ( F_12 ( V_29 + V_25 ) ) {
V_27 = V_27 * 193939 % 47629 ;
V_29 [ V_25 ] . V_21 = V_27 % 99 ;
F_11 ( V_29 + V_25 , & V_10 ) ;
V_22 ++ ;
} else {
F_16 ( V_29 + V_25 , & V_10 ) ;
V_22 -- ;
}
F_19 ( V_22 ) ;
}
for ( V_25 = 0 ; V_25 < F_26 ( V_29 ) ; V_25 ++ ) {
if ( F_12 ( V_29 + V_25 ) )
continue;
F_16 ( V_29 + V_25 , & V_10 ) ;
V_22 -- ;
F_19 ( V_22 ) ;
}
F_24 ( V_28 L_5 ) ;
return 0 ;
}
