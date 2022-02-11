void F_1 ( struct V_1 * V_2 , const char * V_3 ,
struct V_4 * V_5 )
{
F_2 ( & V_2 -> V_6 ) ;
F_3 ( & V_2 -> V_6 , V_5 , V_3 ) ;
F_4 ( & V_2 -> V_7 ) ;
}
void F_5 ( struct V_1 * V_2 )
{
struct V_8 * V_9 ;
if ( F_6 ( & V_2 -> V_7 ) )
return;
V_9 = F_7 ( & V_2 -> V_7 , F_8 ( * V_9 ) , V_7 ) ;
F_9 ( V_9 -> V_10 ) ;
F_10 ( & V_9 -> V_7 ) ;
}
void F_11 ( struct V_1 * V_2 )
{
unsigned long V_11 ;
F_12 ( & V_2 -> V_6 , V_11 ) ;
F_5 ( V_2 ) ;
F_13 ( & V_2 -> V_6 , V_11 ) ;
}
void F_14 ( struct V_1 * V_2 )
{
struct V_8 * V_9 ;
F_15 ( V_12 ) ;
F_16 ( & V_2 -> V_6 ) ;
F_17 ( & V_2 -> V_7 , & V_12 ) ;
while ( ! F_6 ( & V_12 ) ) {
V_9 = F_7 ( & V_12 , F_8 ( * V_9 ) , V_7 ) ;
F_18 ( V_9 -> V_10 , V_13 ) ;
F_10 ( & V_9 -> V_7 ) ;
if ( F_6 ( & V_12 ) )
break;
F_19 ( & V_2 -> V_6 ) ;
F_16 ( & V_2 -> V_6 ) ;
}
F_19 ( & V_2 -> V_6 ) ;
}
void F_20 ( struct V_1 * V_2 , struct V_8 * V_14 )
{
V_14 -> V_10 = V_15 ;
if ( F_6 ( & V_14 -> V_7 ) )
F_21 ( & V_14 -> V_7 , & V_2 -> V_7 ) ;
}
void F_22 ( struct V_1 * V_2 , struct V_8 * V_14 , int V_16 )
{
unsigned long V_11 ;
F_12 ( & V_2 -> V_6 , V_11 ) ;
F_20 ( V_2 , V_14 ) ;
F_23 ( V_16 ) ;
F_13 ( & V_2 -> V_6 , V_11 ) ;
}
long F_24 ( struct V_1 * V_2 , struct V_8 * V_14 , int V_16 )
{
if ( F_25 ( V_16 , V_15 ) )
return - V_17 ;
F_22 ( V_2 , V_14 , V_16 ) ;
return 0 ;
}
void F_26 ( struct V_1 * V_2 , struct V_8 * V_14 )
{
F_27 ( V_18 ) ;
if ( ! F_6 ( & V_14 -> V_7 ) )
F_10 ( & V_14 -> V_7 ) ;
}
void F_28 ( struct V_1 * V_2 , struct V_8 * V_14 )
{
unsigned long V_11 ;
F_27 ( V_18 ) ;
if ( ! F_29 ( & V_14 -> V_7 ) ) {
F_12 ( & V_2 -> V_6 , V_11 ) ;
F_10 ( & V_14 -> V_7 ) ;
F_13 ( & V_2 -> V_6 , V_11 ) ;
}
}
