int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
while ( ( V_3 = V_2 -> V_4 ( V_2 -> V_5 ) ) == 0 )
;
V_2 -> V_3 = V_3 ;
return V_3 ;
}
void F_2 ( unsigned long V_6 )
{
int V_7 ;
int V_3 ;
unsigned long V_8 ;
struct V_1 * V_2 = (struct V_1 * ) V_6 ;
F_3 ( & V_2 -> V_9 , V_8 ) ;
switch ( V_2 -> V_10 ) {
case V_11 :
V_2 -> V_10 = V_12 ;
F_4 ( & V_2 -> V_9 , V_8 ) ;
break;
case V_12 :
V_2 -> V_10 = V_13 ;
case V_13 :
F_4 ( & V_2 -> V_9 , V_8 ) ;
return;
default:
F_4 ( & V_2 -> V_9 , V_8 ) ;
F_5 ( L_1 , V_14 , V_2 -> V_10 ) ;
return;
}
do {
V_7 = 0 ;
V_3 = V_2 -> V_4 ( V_2 -> V_5 ) ;
F_3 ( & V_2 -> V_9 , V_8 ) ;
switch ( V_2 -> V_10 ) {
case V_12 :
if ( V_3 )
V_2 -> V_10 = V_11 ;
else
V_7 = 1 ;
break;
case V_13 :
V_2 -> V_10 = V_12 ;
V_7 = 1 ;
break;
default:
F_5 ( L_1 , V_14 ,
V_2 -> V_10 ) ;
}
F_4 ( & V_2 -> V_9 , V_8 ) ;
} while ( V_7 );
V_2 -> V_3 = V_3 ;
}
int F_6 ( void * V_15 , struct V_1 * V_2 ,
void * V_5 , int (* V_4)( void * ) , char * V_16 )
{
V_2 -> V_15 = V_15 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_4 = V_4 ;
snprintf ( V_2 -> V_16 , sizeof( V_2 -> V_16 ) , L_2 , V_16 ) ;
V_2 -> V_17 = false ;
F_7 ( & V_2 -> V_18 , F_2 , ( unsigned long ) V_2 ) ;
V_2 -> V_10 = V_11 ;
F_8 ( & V_2 -> V_9 ) ;
return 0 ;
}
void F_9 ( struct V_1 * V_2 )
{
unsigned long V_8 ;
bool V_19 ;
V_2 -> V_17 = true ;
do {
F_3 ( & V_2 -> V_9 , V_8 ) ;
V_19 = ( V_2 -> V_10 == V_11 ) ;
F_4 ( & V_2 -> V_9 , V_8 ) ;
} while ( ! V_19 );
F_10 ( & V_2 -> V_18 ) ;
}
void F_11 ( struct V_1 * V_2 , int V_20 )
{
if ( V_2 -> V_17 )
return;
if ( V_20 )
F_12 ( & V_2 -> V_18 ) ;
else
F_2 ( ( unsigned long ) V_2 ) ;
}
void F_13 ( struct V_1 * V_2 )
{
F_14 ( & V_2 -> V_18 ) ;
}
void F_15 ( struct V_1 * V_2 )
{
F_16 ( & V_2 -> V_18 ) ;
}
