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
if ( ! F_5 ( V_9 ) )
F_3 ( & F_6 ( V_9 ) -> V_10 ) ;
F_3 ( & V_9 -> V_11 ) ;
}
void F_7 ( struct V_12 * V_13 , struct V_8 * V_9 )
{
struct V_12 * V_14 , * V_15 , * V_5 = NULL ;
struct V_1 * V_16 = & V_9 -> V_11 ;
F_4 ( V_9 ) ;
F_8 ( ! F_9 ( V_13 ) ) ;
F_8 ( ! F_10 ( & V_13 -> V_10 ) ) ;
if ( F_5 ( V_9 ) )
goto V_17;
V_14 = V_15 = F_6 ( V_9 ) ;
do {
if ( V_13 -> V_18 < V_15 -> V_18 ) {
V_16 = & V_15 -> V_11 ;
break;
}
V_5 = V_15 ;
V_15 = F_11 ( V_15 -> V_10 . V_6 ,
struct V_12 , V_10 ) ;
} while ( V_15 != V_14 );
if ( ! V_5 || V_5 -> V_18 != V_13 -> V_18 )
F_12 ( & V_13 -> V_10 , & V_15 -> V_10 ) ;
V_17:
F_12 ( & V_13 -> V_11 , V_16 ) ;
F_4 ( V_9 ) ;
}
void F_13 ( struct V_12 * V_13 , struct V_8 * V_9 )
{
F_4 ( V_9 ) ;
if ( ! F_10 ( & V_13 -> V_10 ) ) {
if ( V_13 -> V_11 . V_6 != & V_9 -> V_11 ) {
struct V_12 * V_6 ;
V_6 = F_11 ( V_13 -> V_11 . V_6 ,
struct V_12 , V_11 ) ;
if ( F_10 ( & V_6 -> V_10 ) )
F_14 ( & V_6 -> V_10 , & V_13 -> V_10 ) ;
}
F_15 ( & V_13 -> V_10 ) ;
}
F_15 ( & V_13 -> V_11 ) ;
F_4 ( V_9 ) ;
}
static void T_1 F_16 ( int V_19 )
{
struct V_12 * V_14 , * V_20 , * V_21 ;
if ( F_5 ( & V_22 ) ) {
F_17 ( V_19 != 0 ) ;
return;
}
V_20 = V_14 = F_6 ( & V_22 ) ;
F_18 (node_pos, &test_head) {
if ( V_19 -- < 0 )
break;
if ( V_21 == V_14 )
continue;
if ( V_21 -> V_18 == V_20 -> V_18 ) {
F_17 ( ! F_10 ( & V_21 -> V_10 ) ) ;
continue;
}
F_17 ( V_20 -> V_18 > V_21 -> V_18 ) ;
F_17 ( V_20 -> V_10 . V_6 != & V_21 -> V_10 ) ;
V_20 = V_21 ;
}
F_17 ( V_19 != 0 ) ;
F_17 ( V_20 -> V_10 . V_6 != & V_14 -> V_10 ) ;
}
static int T_1 F_19 ( void )
{
int V_19 = 0 , V_23 , V_24 ;
unsigned int V_25 = F_20 () ;
F_21 ( V_26 L_4 ) ;
F_22 ( & V_22 ) ;
for ( V_23 = 0 ; V_23 < F_23 ( V_27 ) ; V_23 ++ )
F_24 ( V_27 + V_23 , 0 ) ;
for ( V_24 = 0 ; V_24 < 1000 ; V_24 ++ ) {
V_25 = V_25 * 193939 % 47629 ;
V_23 = V_25 % F_23 ( V_27 ) ;
if ( F_9 ( V_27 + V_23 ) ) {
V_25 = V_25 * 193939 % 47629 ;
V_27 [ V_23 ] . V_18 = V_25 % 99 ;
F_7 ( V_27 + V_23 , & V_22 ) ;
V_19 ++ ;
} else {
F_13 ( V_27 + V_23 , & V_22 ) ;
V_19 -- ;
}
F_16 ( V_19 ) ;
}
for ( V_23 = 0 ; V_23 < F_23 ( V_27 ) ; V_23 ++ ) {
if ( F_9 ( V_27 + V_23 ) )
continue;
F_13 ( V_27 + V_23 , & V_22 ) ;
V_19 -- ;
F_16 ( V_19 ) ;
}
F_21 ( V_26 L_5 ) ;
return 0 ;
}
