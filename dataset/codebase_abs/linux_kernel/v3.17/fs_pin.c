static void F_1 ( struct V_1 * V_2 )
{
F_2 ( F_3 ( V_2 , struct V_3 , V_4 ) ) ;
}
void F_4 ( struct V_3 * V_5 )
{
if ( F_5 ( & V_5 -> V_6 ) )
F_6 ( & V_5 -> V_4 , F_1 ) ;
}
void F_7 ( struct V_3 * V_7 )
{
F_8 ( & V_8 ) ;
F_9 ( & V_7 -> V_9 ) ;
F_9 ( & V_7 -> V_10 ) ;
F_10 ( & V_8 ) ;
}
void F_11 ( struct V_3 * V_7 , struct V_11 * V_12 )
{
F_8 ( & V_8 ) ;
F_12 ( & V_7 -> V_10 , & V_12 -> V_13 -> V_14 ) ;
F_12 ( & V_7 -> V_9 , & F_13 ( V_12 ) -> V_15 ) ;
F_10 ( & V_8 ) ;
}
void F_14 ( struct V_16 * V_12 )
{
while ( 1 ) {
struct V_17 * V_5 ;
struct V_3 * V_7 ;
F_15 () ;
V_5 = F_16 ( V_12 -> V_15 . V_18 ) ;
if ( ! V_5 ) {
F_17 () ;
break;
}
V_7 = F_18 ( V_5 , struct V_3 , V_9 ) ;
if ( ! F_19 ( & V_7 -> V_6 ) ) {
F_17 () ;
F_20 () ;
continue;
}
F_17 () ;
V_7 -> V_19 ( V_7 ) ;
}
}
void F_21 ( struct V_20 * V_21 )
{
while ( 1 ) {
struct V_17 * V_5 ;
struct V_3 * V_7 ;
F_15 () ;
V_5 = F_16 ( V_21 -> V_14 . V_18 ) ;
if ( ! V_5 ) {
F_17 () ;
break;
}
V_7 = F_18 ( V_5 , struct V_3 , V_10 ) ;
if ( ! F_19 ( & V_7 -> V_6 ) ) {
F_17 () ;
F_20 () ;
continue;
}
F_17 () ;
V_7 -> V_19 ( V_7 ) ;
}
}
