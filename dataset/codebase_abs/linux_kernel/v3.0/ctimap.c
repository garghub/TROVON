int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int (* F_2)( void * , struct V_3 * ) , void * V_5 )
{
struct V_1 * V_6 , * V_7 , * V_8 ;
struct V_3 * V_9 , * V_10 ;
V_8 = V_2 ;
if ( F_3 ( V_8 ) ) {
V_4 -> V_11 = V_4 -> V_12 ;
F_2 ( V_5 , V_4 ) ;
F_4 ( & V_4 -> V_13 , V_8 ) ;
return 0 ;
}
F_5 (pos, head) {
V_10 = F_6 ( V_6 , struct V_3 , V_13 ) ;
if ( V_10 -> V_14 > V_4 -> V_14 ) {
break;
}
}
if ( V_6 != V_8 ) {
V_7 = V_6 -> V_15 ;
if ( V_7 == V_8 )
V_7 = V_8 -> V_15 ;
F_7 ( & V_4 -> V_13 , V_6 -> V_15 , V_6 ) ;
} else {
V_7 = V_8 -> V_15 ;
V_6 = V_8 -> V_11 ;
F_8 ( & V_4 -> V_13 , V_8 ) ;
}
V_9 = F_6 ( V_7 , struct V_3 , V_13 ) ;
V_10 = F_6 ( V_6 , struct V_3 , V_13 ) ;
V_4 -> V_11 = V_10 -> V_12 ;
F_2 ( V_5 , V_4 ) ;
V_9 -> V_11 = V_4 -> V_12 ;
F_2 ( V_5 , V_9 ) ;
return 0 ;
}
int F_9 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int (* F_2)( void * , struct V_3 * ) , void * V_5 )
{
struct V_1 * V_11 , * V_7 , * V_8 ;
struct V_3 * V_9 , * V_16 ;
V_8 = V_2 ;
if ( F_3 ( V_8 ) )
return 0 ;
V_7 = ( V_4 -> V_13 . V_15 == V_8 ) ? V_8 -> V_15 : V_4 -> V_13 . V_15 ;
V_11 = ( V_4 -> V_13 . V_11 == V_8 ) ? V_8 -> V_11 : V_4 -> V_13 . V_11 ;
if ( V_7 == & V_4 -> V_13 ) {
V_4 -> V_11 = V_4 -> V_12 = V_4 -> V_17 = V_4 -> V_14 = 0 ;
F_2 ( V_5 , V_4 ) ;
F_10 ( & V_4 -> V_13 ) ;
return 0 ;
}
V_9 = F_6 ( V_7 , struct V_3 , V_13 ) ;
V_16 = F_6 ( V_11 , struct V_3 , V_13 ) ;
V_9 -> V_11 = V_16 -> V_12 ;
F_2 ( V_5 , V_9 ) ;
F_10 ( & V_4 -> V_13 ) ;
return 0 ;
}
void F_11 ( struct V_1 * V_8 )
{
struct V_3 * V_4 ;
struct V_1 * V_6 ;
while ( ! F_3 ( V_8 ) ) {
V_6 = V_8 -> V_11 ;
F_10 ( V_6 ) ;
V_4 = F_6 ( V_6 , struct V_3 , V_13 ) ;
F_12 ( V_4 ) ;
}
}
