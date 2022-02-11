void F_1 ( struct V_1 * V_2 , unsigned long V_3 )
{
long V_4 ;
V_4 = F_2 ( V_3 , & V_2 -> V_5 ) ;
F_3 ( V_4 < 0 ) ;
}
void F_4 ( struct V_1 * V_2 , unsigned long V_3 )
{
struct V_1 * V_6 ;
for ( V_6 = V_2 ; V_6 ; V_6 = V_6 -> V_7 ) {
long V_4 ;
V_4 = F_5 ( V_3 , & V_6 -> V_5 ) ;
if ( V_4 > V_6 -> V_8 )
V_6 -> V_8 = V_4 ;
}
}
int F_6 ( struct V_1 * V_2 ,
unsigned long V_3 ,
struct V_1 * * V_9 )
{
struct V_1 * V_6 ;
for ( V_6 = V_2 ; V_6 ; V_6 = V_6 -> V_7 ) {
long V_4 ;
V_4 = F_5 ( V_3 , & V_6 -> V_5 ) ;
if ( V_4 > V_6 -> V_10 ) {
F_7 ( V_3 , & V_6 -> V_5 ) ;
V_6 -> V_11 ++ ;
* V_9 = V_6 ;
goto V_12;
}
if ( V_4 > V_6 -> V_8 )
V_6 -> V_8 = V_4 ;
}
return 0 ;
V_12:
for ( V_6 = V_2 ; V_6 != * V_9 ; V_6 = V_6 -> V_7 )
F_1 ( V_6 , V_3 ) ;
return - V_13 ;
}
void F_8 ( struct V_1 * V_2 , unsigned long V_3 )
{
struct V_1 * V_6 ;
for ( V_6 = V_2 ; V_6 ; V_6 = V_6 -> V_7 )
F_1 ( V_6 , V_3 ) ;
}
int F_9 ( struct V_1 * V_2 , unsigned long V_10 )
{
for (; ; ) {
unsigned long V_14 ;
long V_5 ;
V_5 = F_10 ( & V_2 -> V_5 ) ;
if ( V_5 > V_10 )
return - V_15 ;
V_14 = F_11 ( & V_2 -> V_10 , V_10 ) ;
if ( F_10 ( & V_2 -> V_5 ) <= V_5 )
return 0 ;
V_2 -> V_10 = V_14 ;
F_12 () ;
}
}
int F_13 ( const char * V_16 , unsigned long * V_3 )
{
char V_17 [] = L_1 ;
char * V_18 ;
T_1 V_19 ;
if ( ! strncmp ( V_16 , V_17 , sizeof( V_17 ) ) ) {
* V_3 = V_20 ;
return 0 ;
}
V_19 = F_14 ( V_16 , & V_18 ) ;
if ( * V_18 != '\0' )
return - V_21 ;
* V_3 = F_15 ( V_19 / V_22 , ( T_1 ) V_20 ) ;
return 0 ;
}
