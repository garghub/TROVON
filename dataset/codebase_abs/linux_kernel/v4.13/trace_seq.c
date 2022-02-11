static inline void F_1 ( struct V_1 * V_2 )
{
if ( F_2 ( ! V_2 -> V_3 . V_4 ) )
F_3 ( V_2 ) ;
}
int F_4 ( struct V_5 * V_6 , struct V_1 * V_2 )
{
int V_7 ;
F_1 ( V_2 ) ;
V_7 = F_5 ( V_6 , & V_2 -> V_3 ) ;
if ( ! V_7 )
F_3 ( V_2 ) ;
return V_7 ;
}
void F_6 ( struct V_1 * V_2 , const char * V_8 , ... )
{
unsigned int V_9 = V_2 -> V_3 . V_10 ;
T_1 V_11 ;
if ( V_2 -> V_12 )
return;
F_1 ( V_2 ) ;
va_start ( V_11 , V_8 ) ;
F_7 ( & V_2 -> V_3 , V_8 , V_11 ) ;
va_end ( V_11 ) ;
if ( F_2 ( F_8 ( & V_2 -> V_3 ) ) ) {
V_2 -> V_3 . V_10 = V_9 ;
V_2 -> V_12 = 1 ;
}
}
void F_9 ( struct V_1 * V_2 , const unsigned long * V_13 ,
int V_14 )
{
unsigned int V_9 = V_2 -> V_3 . V_10 ;
if ( V_2 -> V_12 )
return;
F_1 ( V_2 ) ;
F_10 ( & V_2 -> V_3 , L_1 , V_14 , V_13 ) ;
if ( F_2 ( F_8 ( & V_2 -> V_3 ) ) ) {
V_2 -> V_3 . V_10 = V_9 ;
V_2 -> V_12 = 1 ;
}
}
void F_11 ( struct V_1 * V_2 , const char * V_8 , T_1 args )
{
unsigned int V_9 = V_2 -> V_3 . V_10 ;
if ( V_2 -> V_12 )
return;
F_1 ( V_2 ) ;
F_7 ( & V_2 -> V_3 , V_8 , args ) ;
if ( F_2 ( F_8 ( & V_2 -> V_3 ) ) ) {
V_2 -> V_3 . V_10 = V_9 ;
V_2 -> V_12 = 1 ;
}
}
void F_12 ( struct V_1 * V_2 , const char * V_8 , const T_2 * V_15 )
{
unsigned int V_9 = V_2 -> V_3 . V_10 ;
if ( V_2 -> V_12 )
return;
F_1 ( V_2 ) ;
F_13 ( & V_2 -> V_3 , V_8 , V_15 ) ;
if ( F_2 ( F_8 ( & V_2 -> V_3 ) ) ) {
V_2 -> V_3 . V_10 = V_9 ;
V_2 -> V_12 = 1 ;
return;
}
}
void F_14 ( struct V_1 * V_2 , const char * V_16 )
{
unsigned int V_10 = strlen ( V_16 ) ;
if ( V_2 -> V_12 )
return;
F_1 ( V_2 ) ;
if ( V_10 > F_15 ( V_2 ) ) {
V_2 -> V_12 = 1 ;
return;
}
F_16 ( & V_2 -> V_3 , V_16 , V_10 ) ;
}
void F_17 ( struct V_1 * V_2 , unsigned char V_17 )
{
if ( V_2 -> V_12 )
return;
F_1 ( V_2 ) ;
if ( F_15 ( V_2 ) < 1 ) {
V_2 -> V_12 = 1 ;
return;
}
F_18 ( & V_2 -> V_3 , V_17 ) ;
}
void F_19 ( struct V_1 * V_2 , const void * V_18 , unsigned int V_10 )
{
if ( V_2 -> V_12 )
return;
F_1 ( V_2 ) ;
if ( V_10 > F_15 ( V_2 ) ) {
V_2 -> V_12 = 1 ;
return;
}
F_16 ( & V_2 -> V_3 , V_18 , V_10 ) ;
}
void F_20 ( struct V_1 * V_2 , const void * V_18 ,
unsigned int V_10 )
{
unsigned int V_9 = V_2 -> V_3 . V_10 ;
if ( V_2 -> V_12 )
return;
F_1 ( V_2 ) ;
if ( V_10 * 2 > F_15 ( V_2 ) ) {
V_2 -> V_12 = 1 ;
return;
}
F_21 ( & V_2 -> V_3 , V_18 , V_10 ) ;
if ( F_2 ( F_8 ( & V_2 -> V_3 ) ) ) {
V_2 -> V_3 . V_10 = V_9 ;
V_2 -> V_12 = 1 ;
return;
}
}
int F_22 ( struct V_1 * V_2 , const struct V_19 * V_19 )
{
unsigned int V_9 = V_2 -> V_3 . V_10 ;
if ( V_2 -> V_12 )
return 0 ;
F_1 ( V_2 ) ;
if ( F_15 ( V_2 ) < 1 ) {
V_2 -> V_12 = 1 ;
return 0 ;
}
F_23 ( & V_2 -> V_3 , V_19 , L_2 ) ;
if ( F_2 ( F_8 ( & V_2 -> V_3 ) ) ) {
V_2 -> V_3 . V_10 = V_9 ;
V_2 -> V_12 = 1 ;
return 0 ;
}
return 1 ;
}
int F_24 ( struct V_1 * V_2 , char T_3 * V_20 , int V_21 )
{
F_1 ( V_2 ) ;
return F_25 ( & V_2 -> V_3 , V_20 , V_21 ) ;
}
