int
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , bool V_5 )
{
struct V_3 * V_6 ;
do {
V_6 = F_2 ( V_2 -> V_7 ) ;
if ( F_3 ( V_6 == & V_8 ) )
return - V_9 ;
V_4 -> V_10 = V_6 ;
} while ( F_4 ( & V_2 -> V_7 , V_6 , V_4 ) != V_6 );
if ( V_5 )
F_5 ( V_2 ) ;
return 0 ;
}
struct V_3 *
F_6 ( struct V_1 * V_2 , T_1 V_11 )
{
struct V_3 * * V_12 = & V_2 -> V_7 ;
struct V_3 * V_4 ;
unsigned long V_13 ;
if ( F_7 ( ! V_2 -> V_7 ) )
return NULL ;
F_8 ( & V_2 -> V_14 , V_13 ) ;
while ( ( V_4 = F_9 ( * V_12 ) ) ) {
if ( V_4 -> V_11 != V_11 )
V_12 = & V_4 -> V_10 ;
else if ( F_4 ( V_12 , V_4 , V_4 -> V_10 ) == V_4 )
break;
}
F_10 ( & V_2 -> V_14 , V_13 ) ;
return V_4 ;
}
void F_11 ( void )
{
struct V_1 * V_2 = V_15 ;
struct V_3 * V_4 , * V_6 , * V_10 ;
for (; ; ) {
do {
V_4 = F_2 ( V_2 -> V_7 ) ;
V_6 = ! V_4 && ( V_2 -> V_13 & V_16 ) ?
& V_8 : NULL ;
} while ( F_4 ( & V_2 -> V_7 , V_4 , V_6 ) != V_4 );
if ( ! V_4 )
break;
F_12 ( & V_2 -> V_14 ) ;
do {
V_10 = V_4 -> V_10 ;
V_4 -> V_11 ( V_4 ) ;
V_4 = V_10 ;
F_13 () ;
} while ( V_4 );
}
}
