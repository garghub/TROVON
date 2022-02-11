int F_1 ( struct V_1 * V_2 )
{
int V_3 = 1 ;
unsigned long V_4 ;
if ( F_2 ( & V_2 -> V_5 , V_4 ) ) {
V_3 = ( V_2 -> V_6 != 0 ) ;
F_3 ( & V_2 -> V_5 , V_4 ) ;
}
return V_3 ;
}
void F_4 ( struct V_1 * V_2 , const char * V_7 ,
struct V_8 * V_9 )
{
#ifdef F_5
F_6 ( ( void * ) V_2 , sizeof( * V_2 ) ) ;
F_7 ( & V_2 -> V_10 , V_7 , V_9 , 0 ) ;
#endif
V_2 -> V_6 = 0 ;
F_8 ( & V_2 -> V_5 ) ;
F_9 ( & V_2 -> V_11 ) ;
}
static inline struct V_1 *
F_10 ( struct V_1 * V_2 , int V_12 )
{
struct V_13 * V_14 ;
struct V_15 * V_16 ;
int V_17 ;
V_14 = F_11 ( V_2 -> V_11 . V_18 , struct V_13 , V_19 ) ;
if ( V_14 -> type == V_20 ) {
if ( V_12 )
F_12 ( V_14 -> V_21 ) ;
goto V_22;
}
V_17 = 0 ;
do {
struct V_23 * V_18 = V_14 -> V_19 . V_18 ;
F_13 ( & V_14 -> V_19 ) ;
V_16 = V_14 -> V_21 ;
F_14 () ;
V_14 -> V_21 = NULL ;
F_12 ( V_16 ) ;
F_15 ( V_16 ) ;
V_17 ++ ;
if ( V_18 == & V_2 -> V_11 )
break;
V_14 = F_11 ( V_18 , struct V_13 , V_19 ) ;
} while ( V_14 -> type != V_20 );
V_2 -> V_6 += V_17 ;
V_22:
return V_2 ;
}
static inline struct V_1 *
F_16 ( struct V_1 * V_2 )
{
struct V_13 * V_14 ;
V_14 = F_11 ( V_2 -> V_11 . V_18 , struct V_13 , V_19 ) ;
F_12 ( V_14 -> V_21 ) ;
return V_2 ;
}
void T_1 F_17 ( struct V_1 * V_2 )
{
struct V_13 V_14 ;
struct V_15 * V_16 ;
unsigned long V_4 ;
F_18 ( & V_2 -> V_5 , V_4 ) ;
if ( V_2 -> V_6 >= 0 && F_19 ( & V_2 -> V_11 ) ) {
V_2 -> V_6 ++ ;
F_3 ( & V_2 -> V_5 , V_4 ) ;
goto V_22;
}
V_16 = V_24 ;
F_20 ( V_16 , V_25 ) ;
V_14 . V_21 = V_16 ;
V_14 . type = V_26 ;
F_21 ( V_16 ) ;
F_22 ( & V_14 . V_19 , & V_2 -> V_11 ) ;
F_3 ( & V_2 -> V_5 , V_4 ) ;
for (; ; ) {
if ( ! V_14 . V_21 )
break;
F_23 () ;
F_20 ( V_16 , V_25 ) ;
}
V_16 -> V_27 = V_28 ;
V_22:
;
}
int F_24 ( struct V_1 * V_2 )
{
unsigned long V_4 ;
int V_3 = 0 ;
F_18 ( & V_2 -> V_5 , V_4 ) ;
if ( V_2 -> V_6 >= 0 && F_19 ( & V_2 -> V_11 ) ) {
V_2 -> V_6 ++ ;
V_3 = 1 ;
}
F_3 ( & V_2 -> V_5 , V_4 ) ;
return V_3 ;
}
void T_1 F_25 ( struct V_1 * V_2 , int V_29 )
{
struct V_13 V_14 ;
struct V_15 * V_16 ;
unsigned long V_4 ;
F_18 ( & V_2 -> V_5 , V_4 ) ;
V_16 = V_24 ;
V_14 . V_21 = V_16 ;
V_14 . type = V_20 ;
F_22 ( & V_14 . V_19 , & V_2 -> V_11 ) ;
for (; ; ) {
if ( V_2 -> V_6 == 0 )
break;
F_20 ( V_16 , V_25 ) ;
F_3 ( & V_2 -> V_5 , V_4 ) ;
F_23 () ;
F_18 ( & V_2 -> V_5 , V_4 ) ;
}
V_2 -> V_6 = - 1 ;
F_13 ( & V_14 . V_19 ) ;
F_3 ( & V_2 -> V_5 , V_4 ) ;
}
void T_1 F_26 ( struct V_1 * V_2 )
{
F_25 ( V_2 , 0 ) ;
}
int F_27 ( struct V_1 * V_2 )
{
unsigned long V_4 ;
int V_3 = 0 ;
F_18 ( & V_2 -> V_5 , V_4 ) ;
if ( V_2 -> V_6 == 0 ) {
V_2 -> V_6 = - 1 ;
V_3 = 1 ;
}
F_3 ( & V_2 -> V_5 , V_4 ) ;
return V_3 ;
}
void F_28 ( struct V_1 * V_2 )
{
unsigned long V_4 ;
F_18 ( & V_2 -> V_5 , V_4 ) ;
if ( -- V_2 -> V_6 == 0 && ! F_19 ( & V_2 -> V_11 ) )
V_2 = F_16 ( V_2 ) ;
F_3 ( & V_2 -> V_5 , V_4 ) ;
}
void F_29 ( struct V_1 * V_2 )
{
unsigned long V_4 ;
F_18 ( & V_2 -> V_5 , V_4 ) ;
V_2 -> V_6 = 0 ;
if ( ! F_19 ( & V_2 -> V_11 ) )
V_2 = F_10 ( V_2 , 1 ) ;
F_3 ( & V_2 -> V_5 , V_4 ) ;
}
void F_30 ( struct V_1 * V_2 )
{
unsigned long V_4 ;
F_18 ( & V_2 -> V_5 , V_4 ) ;
V_2 -> V_6 = 1 ;
if ( ! F_19 ( & V_2 -> V_11 ) )
V_2 = F_10 ( V_2 , 0 ) ;
F_3 ( & V_2 -> V_5 , V_4 ) ;
}
