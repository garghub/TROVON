void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_1 * V_5 , * V_6 ;
#ifndef F_2
F_3 ( F_4 () ) ;
#endif
V_5 = V_4 -> V_7 ;
do {
V_6 = V_5 ;
V_2 -> V_8 = V_5 ;
F_5 () ;
} while ( ( V_5 = F_6 ( & V_4 -> V_7 , V_6 , V_2 ) ) != V_6 );
}
void F_7 ( struct V_1 * V_9 , struct V_1 * V_10 ,
struct V_3 * V_4 )
{
struct V_1 * V_5 , * V_6 ;
#ifndef F_2
F_3 ( F_4 () ) ;
#endif
V_5 = V_4 -> V_7 ;
do {
V_6 = V_5 ;
V_10 -> V_8 = V_5 ;
F_5 () ;
} while ( ( V_5 = F_6 ( & V_4 -> V_7 , V_6 , V_9 ) ) != V_6 );
}
struct V_1 * F_8 ( struct V_3 * V_4 )
{
struct V_1 * V_5 , * V_6 , * V_8 ;
#ifndef F_2
F_3 ( F_4 () ) ;
#endif
V_5 = V_4 -> V_7 ;
do {
if ( V_5 == NULL )
return NULL ;
V_6 = V_5 ;
V_8 = V_5 -> V_8 ;
F_5 () ;
} while ( ( V_5 = F_6 ( & V_4 -> V_7 , V_6 , V_8 ) ) != V_6 );
return V_5 ;
}
struct V_1 * F_9 ( struct V_3 * V_4 )
{
#ifndef F_2
F_3 ( F_4 () ) ;
#endif
return F_10 ( & V_4 -> V_7 , NULL ) ;
}
