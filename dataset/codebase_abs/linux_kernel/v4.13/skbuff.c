void F_1 ( struct V_1 * V_2 , enum V_3 V_4 )
{
const void * V_5 = F_2 ( 0 ) ;
int V_6 = F_3 ( F_4 ( V_4 ) ) ;
F_5 ( V_2 , V_4 , F_6 ( & V_2 -> V_7 ) , V_6 , V_5 ) ;
}
void F_7 ( struct V_1 * V_2 , enum V_3 V_4 )
{
const void * V_5 = F_2 ( 0 ) ;
if ( V_2 ) {
int V_6 = F_8 ( F_4 ( V_4 ) ) ;
F_5 ( V_2 , V_4 , F_6 ( & V_2 -> V_7 ) , V_6 , V_5 ) ;
}
}
void F_9 ( struct V_1 * V_2 , enum V_3 V_4 )
{
const void * V_5 = F_2 ( 0 ) ;
int V_6 = F_3 ( F_4 ( V_4 ) ) ;
F_5 ( V_2 , V_4 , F_6 ( & V_2 -> V_7 ) , V_6 , V_5 ) ;
F_10 ( V_2 ) ;
}
void F_11 ( struct V_1 * V_2 , enum V_3 V_4 )
{
const void * V_5 = F_2 ( 0 ) ;
if ( V_2 ) {
int V_6 ;
F_12 ( & V_2 -> V_7 ) ;
V_6 = F_13 ( F_4 ( V_4 ) ) ;
F_5 ( V_2 , V_4 , F_6 ( & V_2 -> V_7 ) , V_6 , V_5 ) ;
F_14 ( V_2 ) ;
}
}
void F_15 ( struct V_1 * V_2 , enum V_3 V_4 )
{
const void * V_5 = F_2 ( 0 ) ;
if ( V_2 ) {
int V_6 ;
F_12 ( & V_2 -> V_7 ) ;
V_6 = F_13 ( F_4 ( V_4 ) ) ;
F_5 ( V_2 , V_4 , F_6 ( & V_2 -> V_7 ) , V_6 , V_5 ) ;
F_14 ( V_2 ) ;
}
}
void F_16 ( struct V_8 * V_9 )
{
const void * V_5 = F_2 ( 0 ) ;
struct V_1 * V_2 ;
while ( ( V_2 = F_17 ( ( V_9 ) ) ) != NULL ) {
int V_6 = F_13 ( F_4 ( V_10 ) ) ;
F_5 ( V_2 , V_10 ,
F_6 ( & V_2 -> V_7 ) , V_6 , V_5 ) ;
F_14 ( V_2 ) ;
}
}
