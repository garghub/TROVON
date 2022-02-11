static bool F_1 ( unsigned long V_1 )
{
unsigned long V_2 = F_2 ( V_1 ) ;
while ( V_2 > 1 ) {
if ( ( V_1 % V_2 ) == 0 )
break;
V_2 -- ;
}
return V_2 == 1 ;
}
static unsigned long F_3 ( unsigned long V_1 )
{
while ( V_1 < V_3 && ! F_1 ( ++ V_1 ) )
;
return V_1 ;
}
static unsigned long F_4 ( unsigned long V_1 ,
unsigned long * V_4 ,
unsigned long V_5 ,
unsigned long V_6 )
{
unsigned long V_7 ;
V_7 = 2 * V_1 ;
if ( V_7 < V_5 )
V_7 = F_5 ( V_5 , V_1 ) ;
while ( V_7 < V_6 ) {
F_6 ( V_7 , V_4 ) ;
V_7 += V_1 ;
}
return V_1 ;
}
static bool F_7 ( unsigned long V_1 )
{
const struct V_8 * V_4 ;
struct V_8 * V_9 ;
unsigned long V_10 , V_2 ;
V_10 = 2 * V_1 ;
if ( V_10 < V_1 )
return false ;
V_10 = F_8 ( V_10 , V_11 ) ;
V_9 = F_9 ( sizeof( * V_9 ) + F_10 ( V_10 ) ,
V_12 | V_13 ) ;
if ( ! V_9 )
return false ;
F_11 ( & V_14 ) ;
V_4 = F_12 ( V_8 , F_13 ( & V_14 ) ) ;
if ( V_1 < V_4 -> V_15 ) {
F_14 ( V_9 ) ;
goto V_16;
}
F_15 ( V_9 -> V_8 , V_10 ) ;
F_16 ( V_9 -> V_8 , V_4 -> V_8 , V_4 -> V_10 ) ;
for ( V_2 = 2UL ; V_2 < V_10 ; V_2 = F_17 ( V_9 -> V_8 , V_10 , V_2 + 1 ) )
V_9 -> V_15 = F_4 ( V_2 , V_9 -> V_8 , V_4 -> V_10 , V_10 ) ;
V_9 -> V_10 = V_10 ;
F_18 ( V_9 -> V_15 <= V_1 ) ;
F_19 ( V_8 , V_9 ) ;
if ( V_4 != & V_17 )
F_20 ( (struct V_8 * ) V_4 , V_18 ) ;
V_16:
F_21 ( & V_14 ) ;
return true ;
}
static void F_22 ( void )
{
const struct V_8 * V_4 ;
F_11 ( & V_14 ) ;
V_4 = F_12 ( V_8 , F_13 ( & V_14 ) ) ;
if ( V_4 != & V_17 ) {
F_19 ( V_8 , & V_17 ) ;
F_20 ( (struct V_8 * ) V_4 , V_18 ) ;
}
F_21 ( & V_14 ) ;
}
unsigned long F_23 ( unsigned long V_1 )
{
const struct V_8 * V_4 ;
F_24 () ;
V_4 = F_25 ( V_8 ) ;
while ( V_1 >= V_4 -> V_15 ) {
F_26 () ;
if ( ! F_7 ( V_1 ) )
return F_3 ( V_1 ) ;
F_24 () ;
V_4 = F_25 ( V_8 ) ;
}
V_1 = F_17 ( V_4 -> V_8 , V_4 -> V_15 , V_1 + 1 ) ;
F_26 () ;
return V_1 ;
}
bool F_27 ( unsigned long V_1 )
{
const struct V_8 * V_4 ;
bool V_19 ;
F_24 () ;
V_4 = F_25 ( V_8 ) ;
while ( V_1 >= V_4 -> V_10 ) {
F_26 () ;
if ( ! F_7 ( V_1 ) )
return F_1 ( V_1 ) ;
F_24 () ;
V_4 = F_25 ( V_8 ) ;
}
V_19 = F_28 ( V_1 , V_4 -> V_8 ) ;
F_26 () ;
return V_19 ;
}
static void F_29 ( void )
{
const struct V_8 * V_4 ;
char * V_20 ;
V_20 = F_9 ( V_21 , V_12 ) ;
F_24 () ;
V_4 = F_25 ( V_8 ) ;
if ( V_20 )
F_30 ( true , V_20 , V_4 -> V_8 , V_4 -> V_10 ) ;
F_31 ( L_1 ,
V_4 -> V_15 , V_4 -> V_10 , V_4 -> V_8 [ F_32 ( V_4 -> V_10 ) - 1 ] , V_20 ) ;
F_26 () ;
F_14 ( V_20 ) ;
}
static int F_33 ( unsigned long V_22 )
{
unsigned long V_1 , V_15 ;
if ( ! V_22 )
return 0 ;
for ( V_15 = 0 , V_1 = 2 ; V_1 < V_22 ; V_1 ++ ) {
bool V_23 = F_1 ( V_1 ) ;
bool V_24 = F_27 ( V_1 ) ;
if ( V_23 != V_24 ) {
F_34 ( L_2 ,
V_1 , V_23 ? L_3 : L_4 , V_24 ? L_3 : L_4 ) ;
goto V_25;
}
if ( ! V_23 )
continue;
if ( F_23 ( V_15 ) != V_1 ) {
F_34 ( L_5 ,
V_15 , V_1 , F_23 ( V_15 ) ) ;
goto V_25;
}
V_15 = V_1 ;
}
F_31 ( L_6 , V_1 , V_15 ) ;
return 0 ;
V_25:
F_29 () ;
return - V_26 ;
}
static int T_1 F_35 ( void )
{
return F_33 ( V_27 ) ;
}
static void T_2 F_36 ( void )
{
F_22 () ;
}
