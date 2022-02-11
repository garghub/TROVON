static void F_1 ( struct V_1 * V_2 , int V_3 )
{
const char V_4 [] = L_1 ;
int V_5 = 0 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < ( sizeof( V_4 ) - 1 ) ; V_6 ++ ) {
if ( ! ( V_3 & ( 1 << V_6 ) ) )
continue;
if ( V_5 )
F_2 ( V_2 , '|' ) ;
V_5 = 1 ;
F_2 ( V_2 , V_4 [ V_6 ] ) ;
}
if ( ! V_5 )
F_2 ( V_2 , 'R' ) ;
}
static void F_3 ( struct V_7 * V_8 ,
struct V_9 * V_10 ,
struct V_1 * V_2 , int V_11 )
{
const char * V_12 ;
int V_13 ;
V_12 = ( char * ) ( V_10 -> V_14 + V_8 -> V_15 ) ;
V_13 = V_2 -> V_13 ;
F_4 ( V_2 , L_2 ,
V_8 -> V_16 , V_12 ) ;
F_5 ( V_2 ) ;
V_12 = & V_2 -> V_17 [ V_13 ] ;
F_6 ( V_8 -> V_18 -> V_19 , V_12 , V_11 ) ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_9 * V_10 ,
struct V_20 * V_18 , void * V_21 )
{
struct V_7 * V_8 ;
unsigned long long V_3 ;
if ( F_8 ( V_2 , V_18 , L_3 , V_10 , & V_3 , 1 ) )
return F_2 ( V_2 , '!' ) ;
V_8 = F_9 ( V_18 , L_4 ) ;
if ( V_8 ) {
F_3 ( V_8 , V_10 , V_2 , V_3 ) ;
F_2 ( V_2 , ':' ) ;
}
F_4 ( V_2 , L_5 , V_3 ) ;
if ( F_8 ( V_2 , V_18 , L_6 , V_10 , & V_3 , 0 ) == 0 )
F_4 ( V_2 , L_7 , V_3 ) ;
if ( F_8 ( V_2 , V_18 , L_8 , V_10 , & V_3 , 1 ) == 0 )
F_4 ( V_2 , L_9 , V_3 ) ;
if ( F_8 ( V_2 , V_18 , L_10 , V_10 , & V_3 , 0 ) == 0 )
F_4 ( V_2 , L_11 , V_3 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_9 * V_10 ,
struct V_20 * V_18 , void * V_21 )
{
struct V_7 * V_8 ;
unsigned long long V_3 ;
if ( F_8 ( V_2 , V_18 , L_12 , V_10 , & V_3 , 1 ) )
return F_2 ( V_2 , '!' ) ;
V_8 = F_9 ( V_18 , L_13 ) ;
if ( V_8 ) {
F_3 ( V_8 , V_10 , V_2 , V_3 ) ;
F_2 ( V_2 , ':' ) ;
}
F_4 ( V_2 , L_14 , V_3 ) ;
if ( F_8 ( V_2 , V_18 , L_15 , V_10 , & V_3 , 0 ) == 0 )
F_4 ( V_2 , L_16 , ( int ) V_3 ) ;
if ( F_8 ( V_2 , V_18 , L_17 , V_10 , & V_3 , 0 ) == 0 )
F_1 ( V_2 , V_3 ) ;
F_11 ( V_2 , L_18 ) ;
if ( F_8 ( V_2 , V_18 , L_19 , V_10 , & V_3 , 1 ) )
return F_2 ( V_2 , '!' ) ;
V_8 = F_9 ( V_18 , L_20 ) ;
if ( V_8 ) {
F_3 ( V_8 , V_10 , V_2 , V_3 ) ;
F_2 ( V_2 , ':' ) ;
}
F_4 ( V_2 , L_5 , V_3 ) ;
if ( F_8 ( V_2 , V_18 , L_21 , V_10 , & V_3 , 0 ) == 0 )
F_4 ( V_2 , L_22 , ( int ) V_3 ) ;
return 0 ;
}
int F_12 ( struct V_19 * V_19 )
{
F_13 ( V_19 , - 1 , L_23 , L_24 ,
F_10 , NULL ) ;
F_13 ( V_19 , - 1 , L_23 , L_25 ,
F_7 , NULL ) ;
F_13 ( V_19 , - 1 , L_23 , L_26 ,
F_7 , NULL ) ;
return 0 ;
}
void F_14 ( struct V_19 * V_19 )
{
F_15 ( V_19 , - 1 , L_23 , L_24 ,
F_10 , NULL ) ;
F_15 ( V_19 , - 1 , L_23 , L_25 ,
F_7 , NULL ) ;
F_15 ( V_19 , - 1 , L_23 , L_26 ,
F_7 , NULL ) ;
}
